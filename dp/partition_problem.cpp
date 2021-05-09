#include<bits/stdc++.h>
using namespace std;
int f(int a[],int sum,int n){
    if(sum==0)
        return 1;
    if(n==0 && sum!=0)
        return 0;
    if(a[n]>sum)
        return 0;
    return (f(a,sum-a[n],n-1),f(a,sum,n-1));
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2!=0){
        cout<<"NO";
        return 0;
    }
        
    int ans=f(a,sum/2,n-1);
    if(ans%2==0)
        cout<<"YES";
    else
        cout<<"NO";
}