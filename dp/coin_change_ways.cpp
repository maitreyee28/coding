#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
        cin>>a[i];
    int dp[n+3]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i-a[j]>=0){
                dp[i]+=dp[i-a[j]];
            }
        }
    }
    cout<<dp[n];
}