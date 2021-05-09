#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m]={0};
    int t;
    for(int i=0;i<t;i++){
        int r,c;
        cin>>r>>c;
        a[r][c]=-1;
    }
    int dp[n][m]={0};
    for(int i=0;i<n;i++){
        if(a[i][0]==-1)
            break;
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++){
        if(a[0][i]==-1)
            break;
        dp[0][i]=1;
    }
    if(a[0][0]==-1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i-1][j])
                dp[i][j]=dp[i][j-1];
            else if(a[i][j-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n-1][m-1];
}