#include<bits/stdc++.h>
using namespace std;
int f(int a[],int n){
    priority_queue<int,vector<int>,greater<int> >pq(a,a+n);
    int len=pq.top();
    pq.pop();
    int cost=0;
    while(!pq.empty()){
        int add=pq.top();
        pq.pop();
        len+=add;
        cost+=len;
    }
    return cost;
}
int main(){
    int n;
    cin>>n;
    int len[n];
    for(int i=0;i<n;i++){
        cin>>len[i];
    }
    int ans=f(len,n);
    cout<<ans;
}