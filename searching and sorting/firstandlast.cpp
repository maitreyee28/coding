#include<bits/stdc++.h>
using namespace std;

int firstOcc(int a[],int n,int key){
    int s=0;
    int e=n-1;

    int ans=-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == key){
            ans=mid;
            e=mid-1;
        }
        else if(a[mid] > key){
            e = mid-1;
        }
        else
            s = mid+1;
    }
    return ans;
}

int lastOcc(int a[],int n,int key){
     int s=0;
    int e=n-1;

    int ans=-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == key){
            ans=mid;
            s=mid + 1;
        }
        else if(a[mid] > key){
            e = mid-1;
        }
        else
            s = mid+1;
    }
    return ans;
}

int main(){
    int a[]={1,2,3,4,4,4,5,5,6,8,9};
    int n=11;

    cout<<firstOcc(a,n,4)<<endl<<lastOcc(a,n,4);
}