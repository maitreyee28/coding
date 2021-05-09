#include<bits/stdc++.h>
using namespace std;
int n,W;
int wt[100],val[100];

int f(int n,int w){
    if(w==0 || n==0)
        return 0;
    if(wt[n-1]>w)
        return f(n-1,w);
    return max(val[n-1]+f(n-1,w-wt[n-1]),f(n-1,w));
}
int main(){
    cin>>n>>W;
    
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
        cin>>wt[i];
    cout<<f(n,W);
        
}