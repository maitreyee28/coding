#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int s=0;
    int e=n;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid == n){
            return ans;
        }
        if(mid*mid < n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
}