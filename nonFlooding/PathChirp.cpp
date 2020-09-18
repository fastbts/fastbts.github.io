#include <cerrno>
#include <unistd.h>
#include <netinet/in.h>
#include <linux/types.h>
#include <sys/socket.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/netfilter.h>
#include <cassert>
#include <libnetfilter_queue/libnetfilter_queue.h>
#include <signal.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
static void *verdict_thread(void *t);

//struct nfq_handle
//{
//    struct nfnl_handle *nfnlh;
//    struct nfnl_subsys_handle *nfnlssh;
//    struct nfq_q_handle *qh_list;
//};
//
//struct nfnl_subsys_handle {
// struct nfnl_handle  *nfnlh;
// u_int32_t  subscriptions;
// u_int8_t  subsys_id;
// u_int8_t  cb_count;
// struct nfnl_callback  *cb; /* array of callbacks */
//};
//
//#define  NFNL_MAX_SUBSYS   16 /* enough for now */
//
//#define NFNL_F_SEQTRACK_ENABLED  (1 << 0)
//
//struct nfnl_handle {
// int   fd;
// struct sockaddr_nl local;
// struct sockaddr_nl peer;
// u_int32_t  subscriptions;
// u_int32_t  seq;
// u_int32_t  dump;
// u_int32_t  rcv_buffer_size; /* for nfnl_catch */
// u_int32_t  flags;
// struct nlmsghdr  *last_nlhdr;
// struct nfnl_subsys_handle subsys[NFNL_MAX_SUBSYS+1];
//};


struct m_packet{
    char* buf;
    int rv;
};

deque<m_packet>p_pool;//packet for process
pthread_mutex_t queue_lock;

//int fff=0;
//bool fflag=0;
//nfq_handle_packet() may call this function to pass the packet to the network interface
static int cb(struct nfq_q_handle *qh, struct nfgenmsg *nfmsg,
              struct nfq_data *nfa, void *data)
{
//	fff++;
//	if(fff==100){
////		fflag=1;
//		while(1);
//	}


	
//	printf("call cb\n");
    u_int32_t id = 0;
    struct nfqnl_msg_packet_hdr *ph;

    ph = nfq_get_msg_packet_hdr(nfa);
    if (ph)
    {
        id = ntohl(ph->packet_id);
    }

//	unsigned char *nf_packet = nullptr;
//	int len = nfq_get_payload(nfa, &nf_packet);
//    if (len < 0) {
//        printf("Can't get payload data");
//	}


	unsigned char *payload;
    int r=nfq_get_payload(nfa,&payload);
    struct iphdr *ip_header=(struct iphdr *)payload;
    struct tcphdr *tcp_header;
    if(ip_header->protocol==IPPROTO_TCP && r>=40 &&ip_header->ihl*4+20<=r){
        tcp_header=(struct tcphdr*)(payload+ip_header->ihl*4);
        
        printf("%u %hu\n",ntohl(tcp_header->seq),ntohs(ip_header->tot_len)-20);
	}

	// parse the packet headers
//	struct iphdr *iph = ((struct iphdr *) nf_packet);

	// display IP HEADERS : ip.h line 45
    // ntohs convert short unsigned int, ntohl do the same for long unsigned int
//    printf("IP{v=%u; ihl=%u; tos=%u; tot_len=%u; id=%u; ttl=%u; protocol=%u; "
//        ,iph->version, iph->ihl*4, iph->tos, ntohs(iph->tot_len), ntohs(iph->id), iph->ttl, iph->protocol);

//	char *saddr = inet_ntoa(*(struct in_addr *)&iph->saddr);
//    printf("saddr=%s; ", saddr);

//    char *daddr = inet_ntoa(*(struct in_addr *)&iph->daddr);
//    printf("daddr=%s}\n", daddr);

    nfq_set_verdict(qh, id, NF_ACCEPT, 0, NULL);
    return 0;
}

//read data
static void *read_thread(void *fa){
    struct nfq_handle *h;
    struct nfq_q_handle *qh;
    int fd;
    int rv;
    char buf[2048];

    h= nfq_open();
    if(h==NULL||nfq_unbind_pf(h, AF_INET)!=0||nfq_bind_pf(h, AF_INET)!=0){
        printf("nfq open failed or bind error");
        return NULL;
    }
    
    qh = nfq_create_queue(h, 80, &cb, NULL);
    if(qh==NULL||nfq_set_mode(qh, NFQNL_COPY_PACKET, 0xffff)!=0){
        printf("create queue error or set mode error");
        return NULL;
    }
    fd = nfq_fd(h);

    pthread_t handle_id;
    pthread_create(&handle_id,NULL,verdict_thread,h);

    //start reading
    for (;;) {
        
        if ((rv= recv(fd, buf, sizeof(buf), 0)) && rv >= 0) {
//            pthread_mutex_lock(&queue_lock);

            //###todo####: repalce the condition with the filter of a certain ip/port/etc. (by parsing buf[] or other methods) 
            if(1){
                //pass the packet directly without waiting
//                nfq_handle_packet(h, buf, rv);

            }
            else{
                //push the packet into the packet pool for verdict_thread() to deal with
                m_packet *pac = new m_packet;
                char *temp = new char[rv];
                memcpy(temp, buf, rv);
                pac->buf = temp;
                pac->rv = rv;
                p_pool.push_back(*pac);
            }
//            pthread_mutex_unlock(&queue_lock);
            continue;
        }
    }

    pthread_join(handle_id,NULL);
    nfq_close(h);
}
double baseTime = 1000000;
double endTime = 10;
double multiple = 1.1;
static bool ifSent(long long t1,long long t2){
	if(t2-t1>baseTime){
		baseTime/=multiple;
		return true;
	}
	return false;
}
static void *verdict_thread(void *t){
    nfq_handle *h = (nfq_handle *)t;
    
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    long long t1=tv.tv_sec*1000000ll+tv.tv_usec;
    
//    printf("res= %lld\n",t2-t1);
    int k=0;
	int last=0;
    while(1){
//    	printf("here");
//		if(p_pool.size()<1000){
//			if(p_pool.size()!=last)
//				printf("%d\n",(int)p_pool.size());
//			last=(int)p_pool.size();
//			continue;
//		}
	    gettimeofday(&tv, NULL);
	    long long t2=tv.tv_sec*1000000ll+tv.tv_usec;
	    if(!ifSent(t1,t2)){
	    	continue;
		}
//	    printf("t2-t1=%lld\n",t2-t1);
//	    if(t2-t1<=1000000)continue;// 1s
//	    printf("1s,t=%lld\n",t2);
	    t1=t2;
//        pthread_mutex_lock(&queue_lock);
        //###todo####: to implement the sending packet logic
        while(!p_pool.empty())
        {
//			if(k%100==1)printf("%d\n",k);
        	k++;
//        	printf("%d\n",k);
//            printf("verdict packet pool~   \n");
            m_packet *tmp = &(p_pool.front());
            nfq_handle_packet(h, tmp->buf, tmp->rv);
            p_pool.pop_front();

        }
//        pthread_mutex_unlock(&queue_lock);
    }

}

int main(int argc, char **argv)
{

    pthread_mutex_init(&queue_lock, NULL);
    pthread_t t1;
    if (pthread_create(&t1, NULL, read_thread, (void*)0) != 0) {
        printf("Create thread %d failed\n", 1);
    }   
    void *returnv1;
    pthread_join(t1, &returnv1);


}


//1. config iptables: iptables -A OUTPUT -d $address -p tcp --dport $port -j NFQUEUE --queue-num 80
//2. config iptables: iptables -A INPUT -s $address -p tcp --sport $port -j NFQUEUE --queue-num 80
//3. g++ -o test non_flooding_new.cpp -lnfnetlink -lnetfilter_queue -std=c++11 -lpthread
//4. sudo ./test
//5. after experiment: iptables -D INPUT 1; iptables -D OUTPUT 1
