#include<bits/stdc++.h>
#define lp(i,n)for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
const int M=3,N=1e5,e[]={1,2,0},o[]={2,0,1};int t,n[M],u[M],w[M][N],x[M];ll m,p,v[M];
void f(ll &g){ll k;g=0;lp(i,M)u[i]=w[i][x[i]];lp(i,M)k=u[o[i]]-u[e[i]],g+=k*k;}
int g(){lp(i,M)if(x[i]+1<n[i])return 1;return 0;}
int main(){
    for(ios_base::sync_with_stdio(0),cin.tie(0),cin>>t;t--;f(p),cout<<min(m,p)<<'\n'){
        lp(i,M)cin>>n[i],x[i]=0;
		lp(i,M){lp(j,n[i])cin>>w[i][j];sort(w[i],w[i]+n[i]);}
		for(f(m);g();){
            lp(i,M)if(v[i]=LLONG_MAX,x[i]+1<n[i])++x[i],f(v[i]),--x[i];
            lp(i,M)if(v[i]<=min(v[o[i]],v[e[i]])){m=min(m,v[i]),++x[i];break;}}
        lp(i,M)x[i]=n[i]-1;}}