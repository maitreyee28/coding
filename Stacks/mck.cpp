#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[6]={1,2,3,4,5,6};
    int b[5]={3,5 , 7,8,9};
    int k=8;
    //vector<pair<int,int> > ans;
    for(int i=0;i<6;i++){
        //int j=4;
        int start=0;
        int end=4;
        
        cout<<"*";
        while(start<end){
            int mid=(start+end)/2;
            if(a[i]+b[mid] > k){
            end=mid-1;
        }
        else if(a[i] + b[mid] < k){
            start=mid+1;
        }
        else{
            cout<<a[i]<<" "<<b[mid]<<endl;
        }
        }
        
    }
}