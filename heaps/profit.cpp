#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    
    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
    }
    int ans=0;
    while(B--){
        // cout<<B;
        int t=pq.top();
        ans+=t;
        pq.pop();
        pq.push(t-1);
    }
    return ans;
}

int main(){
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    int b=3;
    cout<<solve(a,b);
}
