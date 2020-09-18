#include <bits/stdc++.h>
using namespace std;
double p[10005];
double t[10005];
struct point{
	double v;
	int i;
	point(double vv,int ii):v(vv),i(ii){;}
	point(){;}
};
vector<point> res;
int n;
void output(){
//	for(int i=0;i<n;i++)cout<<i<<' ';cout<<endl;
//	for(int i=0;i<n;i++)cout<<p[i]<<' ';cout<<endl;
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++)cout<<res[i].v<<' ';cout<<endl;
//	for(int i=0;i<res.size();i++)cout<<res[i].v<<' ';
}
int main(){
	freopen("record.txt","r",stdin);
	freopen("fastResult.txt","w",stdout);
	while(cin>>n){
		res.clear();
		double deltat=0.1;
		for(int i=0;i<n;i++)cin>>p[i];
		for(int i=0;i<n;i++)t[i]=i*deltat;
		bool ok=0;
		for(int i=0;i<n;i++){
			if(t[i]<5)continue;
			double ma,mi,s,k;
			ma=mi=p[i];s=k=0;
			res.clear();
			for(int j=0;j<=i;j++)
				if(t[j]+2>=t[i])ma=max(ma,p[j]),mi=min(mi,p[j]),s+=p[j],k++,res.push_back(point(p[j],j));
			if((ma-mi)/mi>0.03){
				res.clear();
				continue;
			}
//			output();
			cout<<s/k<<endl;
			ok=1;
			break;
		}
		if(!ok){
			res.clear();
			int i=n-1;
			double ma,mi,s,k;
			ma=mi=p[i];s=k=0;
			for(int j=0;j<=i;j++)
				if(t[j]+2>=t[i])ma=max(ma,p[j]),mi=min(mi,p[j]),s+=p[j],k++,res.push_back(point(p[j],j));
//			output();
			cout<<s/k<<endl;
		}
	}
	return 0;
}
