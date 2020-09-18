#include <bits/stdc++.h>
using namespace std;
double p[10005];
double porigin[10005];
int belong[10005];
double s,a,b;
struct point{
	double res;
	int k;
	int id;
	point(){;}
	point(double rr,int kk,int idd):res(rr),k(kk),id(idd){;}
	bool operator<(const point&p)const{
		return res/k<p.res/p.k;
	}
};
vector<point>res;
int n;
void output(){
//	for(int i=0;i<n;i++)cout<<i<<' ';cout<<endl;
//	for(int i=0;i<n;i++)cout<<porigin[i]<<' ';cout<<endl;
	int tot=0;
	double sum=0;
	vector<pair<int,double> >selected;
	map<int,int> ss;
	for(int i=5;i<res.size()-2;i++){
		tot+=res[i].k;
		sum+=res[i].res;
		ss[res[i].id]=1;
	}
	for(int i=0;i<n;i++)
		if(ss[belong[i]])selected.push_back({i,porigin[i]});

	cout<<selected.size()<<endl;
	for(int i=0;i<selected.size();i++)
		cout<<selected[i].second<<' ';
	cout<<endl;
//	for(int i=0;i<selected.size();i++)
//		cout<<selected[i].second<<' ';	
}
int main(){
	freopen("record.txt","r",stdin);
	freopen("speedtestResult.txt","w",stdout);
	while(cin>>n){
		res.clear();
		s=a=b=0;
		for(int i=0;i<n;i++){
			cin>>a;
			porigin[i]=a;
			p[i]=(a+b)/2*0.1;
			b=a;
			s+=p[i];
		}
		double ave=s/20;
		double ts=0;
		int tk=0;
		int id=0;
		for(int i=0;i<n;i++){
			if(ts+p[i]>ave&&id<19){
				res.push_back(point(ts,tk,id++));
				ts=p[i];
				tk=1;
				belong[i]=id;
			}
			else ts+=p[i],tk++,belong[i]=id;
		}
		res.push_back(point(ts,tk,id++));
		sort(res.begin(),res.end());
//		output();
		int tot=0;
		double sum=0;
		for(int i=5;i<res.size()-2;i++){
			tot+=res[i].k;
			sum+=res[i].res;
		}
		cout<<sum/tot/0.1<<endl;
	//	for(int i=0;i<n;i++)cout<<belong[i]<<' ';
	}
	return 0;
}
