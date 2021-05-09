#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if(n<=1)
        return 1;
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=f(i)*f(n-1-i);
    return ans;
}
int main(){
    //c0=1
    //cn=from 0 to n-1->ci*cn-1-i
    int n;
    cin>>n;
    cout<<f(n);
}