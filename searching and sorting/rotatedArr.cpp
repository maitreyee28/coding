#include<bits/stdc++.h>
using namespace std;

int f(int a[],int n,int key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid = (s+e)/2;

        if(a[mid] == key) return mid;

        else if(a[s] > a[mid]){
            if(a[s] <= key and a[mid] >= key){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        else{
            if(a[mid] <= key and a[e] >= key){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int a[]={4,5,1,2,3};
    int n=5;

    cout<<f(a,n,3);

}