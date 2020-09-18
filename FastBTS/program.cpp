#include <bits/stdc++.h>
using namespace std;
#define CLOCKWISE 1
double p[10005];
double porigin[10005];
double x[10005];
double y[10005];
double mi[10005];
double eps=1e-6;
int n;
double ml;
const double inf=1e18;
double up,down;
struct point{
	double x,y;
	int i;
	point(){;}
	point(double xx,double yy,double ii):x(xx),y(yy),i(ii){;}
	point operator-(const point p){
		point pp;
		pp.x=x-p.x;
		pp.y=y-p.y;
		return pp;
	}
};
double outProd(point p1,point p2){
	return p1.x*p2.y-p1.y*p2.x;
}
bool ccw(point pa,point pb,point pc){
	if(outProd(pb-pa,pc-pa)<=eps)return CLOCKWISE;
}
bool ok(double m){
	for(int i=0;i<n;i++){
		y[i]=i*i+m*p[i]-2*i;
		x[i]=i;
		mi[i]=-2*i-i*i+m*p[i]-1;
	}
	vector<point> stk;
	stk.push_back(point(-1,-inf,-1));
	stk.push_back(point(x[0],y[0],0));
	int q=0;
	for(int i=1;i<n;i++){
		double k=2*i;
		if(q>=stk.size())q=stk.size()-1;
		while(q+1<stk.size()&&stk[q+1].y-k*stk[q+1].x>stk[q].y-k*stk[q].x&&p[i]-p[stk[q+1].i]>=ml)q++;
		while(q>0&&(stk[q-1].y-k*stk[q-1].x>stk[q].y-k*stk[q].x||p[i]-p[stk[q].i]<ml))q--;
		double b=stk[q].y-k*stk[q].x;
		if(b>=mi[i]){
			up=p[i];
			down=p[stk[q].i];
			return true;
		}
		for(int j=stk.size();j>=2&&ccw(stk[j-2],stk[j-1],point(x[i],y[i],i))!=CLOCKWISE;j--)
			stk.pop_back();
		stk.push_back(point(x[i],y[i],i));
	}
	return false;
}
void output(){
//	for(int i=0;i<n;i++)cout<<i<<' ';cout<<endl;
//	for(int i=0;i<n;i++)cout<<porigin[i]<<' ';cout<<endl;
	vector<pair<int,double> > selected;
	for(int i=0;i<n;i++)
		if(porigin[i]>=down&&porigin[i]<=up)
			selected.push_back({i,porigin[i]});
	cout<<selected.size()<<endl;
	for(int i=0;i<selected.size();i++)
		cout<<selected[i].second<<' ';
	cout<<endl;
//	for(int i=0;i<selected.size();i++)
//		cout<<selected[i].second<<' ';
}
int main(){
	freopen("record.txt","r",stdin);
	freopen("programResult.txt","w",stdout);
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>p[i],porigin[i]=p[i];sort(p,p+n);
		ml=(p[n-1]-p[0])/(n-1);
		double res=0;
		double l=0,r=1e9,m;
		while(r>l+eps){
			m=(l+r)/2;
			if(ok(m))res=max(res,m),l=m;
			else r=m;
		}
		int kk=0;
		double sum=0;
		for(int i=0;i<n;i++)
			if(p[i]>=down&&p[i]<=up)
				kk++,sum+=p[i];
//		cout<<up<<'\t'<<down<<'\t'<<kk<<'\t';
		cout<<sum/kk<<endl;
//		output();
	}
	return 0;
}
