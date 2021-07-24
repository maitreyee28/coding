#include<bits/stdc++.h>
using namespace std;
int maxWater(int a[],int n){
    int lmax[n];
    int rmax[n];
    int max_h=INT_MIN;
    for(int i=0;i<n;i++){
        max_h=max(max_h,a[i]);
        lmax[i]=max_h;
    }
    max_h=INT_MIN;
    for(int i=n-1;i>=0;i--){
        max_h=max(max_h,a[i]);
        rmax[i]=max_h;
    }
    int water[n];
    for(int i=0;i<n;i++){
        water[i]=min(lmax[i],rmax[i]) - a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=water[i];
    }
    return ans;
}



int main(){
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << maxWater(arr, n);
}