#include<bits/stdc++.h>
using namespace std;

vector<int> f(int a[],int n){
    vector<int> ans;
    int s=0;
    for(s=0;s<n-1;s++){
        if(a[s+1] < a[s]) break;
    }
    if(s==n-1){
        ans.push_back(-1);
        return ans;
    }
    int e;
    for(e=n-1;e>0;e--){
        if(a[e-1] > a[e]) break;
    }

    int maxEle=a[s];
    int minEle=a[s];

    for(int i=s+1;i<=e;i++){
        if(a[i]>maxEle) maxEle = a[i];
        if(a[i]<minEle) minEle =a[i];
    }
    // cout<<maxEle<<" "<<minEle<<endl;
    for(int i=0;i<s;i++){
        if(a[i] > minEle) s=i;
    }
    for(int i=e+1;i<n;i++){
        if(a[i] < maxEle) e=i;
    }


    for(int i=s;i<=e;i++){
        ans.push_back(a[i]);
    }
    return ans;
}
int main(){
    int a[]={10,12,20,30,25,40,32,31,35,50,60};
    int n=11;

    vector<int> ans=f(a,n);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}