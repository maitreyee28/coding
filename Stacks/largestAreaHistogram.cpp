#include<bits/stdc++.h>
using namespace std;

int f(int a[],int n)
{
    stack<int> s;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(s.empty() || a[i]>=a[s.top()]){
            s.push(i);
        }
        else{
            while(!s.empty() && a[s.top()]>a[i]){
                int curr = s.top();
                s.pop();
                if(s.empty()){
                    ans = max(ans,a[curr]*i);
                }
                else{
                    ans = max(ans,a[curr]*(i-s.top()-1));
                }
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        int curr = s.top();s.pop();
        if(s.empty()){
            ans = max(ans,a[curr]*n);
        }
        else{
            ans = max(ans,a[curr]*(n-s.top()-1));
        }
    }
    return ans;
}

 int main()
 {
     int a[] = {6,2,5,4,5,1,6};
     int n = 7;
     cout<<f(a,n);
 }