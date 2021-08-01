#include<bits/stdc++.h>
using namespace std;
int cntdigs(int n){
    int cnt=0;
    while(n){
        cnt++;
        n=n/10;
    }
    // cout<<cnt<<"*";
    return cnt;
}
long long int genmax(int a[]){
    int n=5;
    // string s='\0';
    long long int ans=a[0];
    for(int i=1;i<n;i++){
        cout<<a[i]<<" "<<ans<<" ";
        int op1= pow(10,2);
        cout<<op1<<" "<<pow(10,2)<<" ";
        int op2= a[i]*(pow(10,cntdigs(ans))) + ans;
        
        int ans=max(op1,op2);
        cout<<op2<<" "<<ans<<endl;
    }
    return ans;
}
int main(){
    int a[]={3,30,34,5,9};
    // cout<<)<<endl;
    cout<<genmax(a);
    
}