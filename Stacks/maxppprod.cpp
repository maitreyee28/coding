#include<bits/stdc++.h>
using namespace std;

int f(int a[],int n){
    vector<int> l,r;
    stack<int> s;
    l.push_back(0);
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && a[i]>=a[s.top()])
            s.pop();
        if(s.empty())
            l.push_back(0);
        else l.push_back(s.top());
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    r.push_back(0);
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && a[i]>=a[s.top()])
            s.pop();
        if(s.empty())
            r.push_back(0);
        else
            r.push_back(s.top());
        s.push(i);
    }
    reverse(r.begin(),r.end());
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,l[i]*r[i]);
    }
    return ans;

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<f(a,n);
}