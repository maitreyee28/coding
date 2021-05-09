#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int n1=a.length();
    int n2=b.length();
    int dp[n1][n2];
    memset(dp,0,sizeof dp);
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            
        }
    }
    cout<<dp[n1][n2];

}