#include<bits/stdc++.h>
using namespace std;

void negpos(int a[],int n){
    int j , curr;
    for(int i=0;i<n;i++){
        curr=a[i];
        if(a[i]>0)
            continue;
        j=i-1;
        while(j>=0 && a[j]>0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=curr;
    }
}

int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    negpos(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}