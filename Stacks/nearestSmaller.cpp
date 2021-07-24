#include<bits/stdc++.h>
using namespace std;
vector<int> f(int a[],int n){
    stack<int> s;
    s.push(a[0]);
    vector<int> ans;
    ans.push_back(-1);
    for(int i=1;i<n;i++){
        if(a[i] > s.top()){
            ans.push_back(s.top());
            s.push(a[i]);
        }
        else{
                while(!s.empty() && s.top() >= a[i]){
                    s.pop();
                }
                if(s.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(s.top());
                s.push(a[i]);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;8 39 27 11 4 24 32 32 1
    int a[n];
    //8 39 27 11 4 24 32 32 1
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans=f(a,n);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}