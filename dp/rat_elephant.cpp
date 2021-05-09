#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int rat[n][m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0)
                rat[i][j]=1;
            else rat[i][j]=rat[i-1][j]+rat[i][j-1];
        }
    }
    cout<<rat[n-1][m-1]<<endl;
    int ele[n][m];
    memset(ele,0,sizeof ele);
    ele[0][0]=1;
    ele[0][1]=1;
    ele[1][0]=1;
    for(int i=2;i<n;i++){
        ele[i][0]=ele[i-1][0]*2;
    }
    for(int i=2;i<m;i++){
        ele[0][i]=ele[0][i-1]*2;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            // if(i==0 && j==0)
            //     ele[i][j]=1;
            int i1=i-1,j1=j-1;
            while (i1>=0){
                ele[i][j]+=ele[i1--][j];
            }
            while (j1>=0){
                // cout<<ele[i][j1]<<"*"<<endl;
                ele[i][j]+=ele[i][j1--];
            
            }
            // cout<<ele[i][j]<<" ";
        }
        // cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ele[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ele[n-1][m-1];
}