#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int cnt=0;
    int temp[100]={0};
    while(i<=mid && j<=e){
        if(a[i] > a[j]){
            cnt+=mid+1-i;
            temp[k++] = a[j];
            j++;
        }
        else{
            temp[k++] = a[i];
            i++;
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }
    return cnt;
}
int invCnt(int a[],int s,int e){
    if(s>=e)
         return 0;
    int mid=(s+e)/2;

    int cnt1=invCnt(a,s,mid);
    int cnt2=invCnt(a,mid+1,e);
    int cnt3=merge(a,s,e);

    return cnt1+cnt2+cnt3;
}
int main(){
    int a[]={1,5,2,6,3,0};
    int n=6;
    cout<<invCnt(a,0,n-1);
}