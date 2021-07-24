#include<bits/stdc++.h>
using namespace std;
int f(int time,vector<int> v){
    priority_queue<int> pq;
    for(int i=0;i<v.size();i++){
        pq.push(v[i]);
    }
    int ans=0;
    while(time--){
        int t=pq.top();
        ans+=t;
        pq.pop();
        pq.push(t/2);
    }
    return ans;
}
int main(){
    int n=5;
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    cout<<f(n,v);
}