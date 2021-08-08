#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int t,n,ans;
int a[N],b[N],v[N],l[N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);ans=0ll;
		for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
		for(int i=1;i<n;++i)a[i]=abs(b[i+1]-b[i]);--n;
		for(int i=1;i<=n;++i){v[i]=a[i];l[i]=i;}
		for(int i=1;i<=n;++i)
		for(int j=i;j;j=l[j]-1) 
		{
			v[j]=gcd(v[j],a[i]);
			while(l[j]>1&&gcd(a[i],v[l[j]-1])==v[j])l[j]=l[l[j]-1];
			if(v[j]>1)ans=max(ans,i-l[j]+1);
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}