#include<bits/stdc++.h>
using namespace std;
int calc(int rank[],int cook,int mid){
    int prata=0;
    for(int i=0;i<cook;i++){
        int s=1;
        int t=0;
        while(t<mid){
            // cout<<"*";
            if(t+(rank[i]*s) <= mid){
                t+=(rank[i]*s);
                prata++;
                s++;
            }
            else break;
        }
    }
    // cout<<prata<<endl;
    return prata;
}
int f(int n,int cook,int rank[]){
    int maxTime=rank[cook-1]*(n*(n+1)/2);
    // cout<<maxTime<<"*"<<endl;
    int s=0;
    int e=maxTime;
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        // cout<<mid<<"$"<<endl;
        int pratas=calc(rank,cook,mid);
        if(pratas>=n){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
          int n;
    cin>>n;
    int cook;
    cin>>cook;
    int rank[cook];
    for (int i = 0; i < cook; i++){
        cin>>rank[i];
    }
    cout<<f(n,cook,rank);
    }
  
}