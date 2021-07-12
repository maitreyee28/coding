#include<bits/stdc++.h>
using namespace std;
int f1(int a[],int n){
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}
int f2(int a[],int n){
    int maxSum=INT_MIN;
    int preSum[20];
    preSum[0]=a[0];
    for(int i=1;i<n;i++)
        preSum[i]=preSum[i-1]+a[i];
    //for(int i=0;i<n;i++)
       // cout<<preSum[i]<<"!";
    int sum;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            sum=preSum[j]-preSum[i-1];
            maxSum=max(maxSum,sum);
        }

    }
    return maxSum;
}
int f3(int a[],int n){
    int currSum=0;
    int maxSum=0;
    for(int i=0;i<n;i++){
        currSum+=a[i];
        if(currSum<0){
            currSum=0;
        }
        maxSum=max(maxSum,currSum);

    }
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    int a[20];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<f1(a,n)<<" * "<<f2(a,n)<<" * "<<f3(a,n);

}
