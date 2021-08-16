#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,P=1e9+7;
int T,n,k,f[N],w[N];
void work(){
	scanf("%d%d",&n,&k);f[0]=1;
	for (int i=1,v=1;i<=k;i++,v=1ll*v*w[n]%P){
		if (n&1) f[i]=1ll*(w[n-1]+1)*f[i-1]%P;
		else f[i]=(1ll*(w[n-1]-1)*f[i-1]%P+v)%P;
	}
	printf("%d\n",f[k]);
}
int main(){
	w[0]=1;
	for (int i=1;i<N;i++)
		w[i]=(w[i-1]<<1)%P;
	for (scanf("%d",&T);T--;work());
	return 0;
}