#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,m,f[maxn];
int _find(int x){
    return x==f[x]?x:f[x]=_find(f[x]);
}
int main(){
	// freopen("S.INP", "r", stdin);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)f[i]=i;
		int ans=0,x,y;
		while(m--){
			cin>>x>>y;
			if(x==y)continue;
			ans++;
			if(_find(x)==_find(y))ans++;
			f[_find(y)]=_find(x);
		}
		cout<<ans<<endl;
	}
	return 0;
}