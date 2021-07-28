#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int n,int key){
    int start=0;int end=n-1;
    while(start <= end){
        int mid = (start+end)/2;

        if(a[mid] == key){
            return mid;
        }
        if(a[mid] > key){
            end = mid-1;
        }
        else
            start= mid+1;
    }
    return -1;
}
int main(){
    int a[]={1,2,3,4,4,4,5,5,6,8,9};
    int n=11;
    cout<<binarySearch(a,11,4);
}