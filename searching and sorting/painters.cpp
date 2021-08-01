#include<bits/stdc++.h>
using namespace std;

int check(int n,int a[],int mid){
    int painters=1;
    int time=0;
    for(int i=0;i<n;i++){
        time+=a[i];
        if(time > mid){
            time=a[i];
            painters++;
        }
    }
    cout<<painters<<endl;
    return painters;
}

int f(int k,int n,int a[]){
    int len=0;
    for(int i=0;i<n;i++)
        len+=a[i];
    int s=0;
    int e=len;
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(n,a,mid) < k){
            cout<<ans<<"*"<<endl;
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int k,n;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<f(k,n,a);
}