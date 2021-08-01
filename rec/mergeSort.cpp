#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int s,int e){
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100];
    while(i<=mid && j<=e){
        if(a[i] > a[j]){
            temp[k++]=a[j++];
        }
        else{
            temp[k++]=a[i++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int l=0;l<k;l++){
        a[l]=temp[l];
    }
}
void mergeSort(int a[],int s,int e){
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    merge(a,s,e);
}
int main(){
    int a[]={1,8,5,4,9,3,2};
    int n=7;

    mergeSort(a,0,6);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";

}