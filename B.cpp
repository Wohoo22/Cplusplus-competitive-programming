#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
cin>>t;
while(t--){
long long int n;
cin>>n;
long long int a[n],sum=0;
sum=sum+2*n-1;
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n-2;i++){
if(a[i]<a[i+1]&&a[i+1]>a[i+2]||a[i]>a[i+1]&&a[i+2]>a[i+1])
sum++;
}
for(int i=0;i<n-3;i++){
    int k=max(a[i+1],a[i+2]);
    int l=min(a[i+1],a[i+2]);
    if(max(a[i],a[i+3])<k&&min(a[i],a[i+3])>l)
    sum++;
}
cout<<sum<<endl;
}
}