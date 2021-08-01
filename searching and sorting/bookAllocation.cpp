#include<bits/stdc++.h>
using namespace std;


bool readable(int pgs[],int books,int students,int mid){
    // cout<<"$";
    int c=1 ;
    int pgsRead=0;
    for(int i=0;i<books;i++){
        if(pgsRead+pgs[i] > mid){
            c++;
            pgsRead=pgs[i];
            if(c>students){
                return false;
            }
        }
        else{
            pgsRead+=pgs[i];
        }
    }
    return true;
}

int f(int pgs[],int books,int students){
    int totalPgs=0;
    for(int i=0;i<books;i++)
        totalPgs += pgs[i];
    // cout<<totalPgs<<endl;
    int s=pgs[0];
    int e=totalPgs;
    int ans=INT_MAX;
    while(s<=e){
        // cout<<"*";
        int mid=(s+e)/2;
        if(readable(pgs,books,students,mid)){
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int books,students;
    cin>>books>>students;
    int pgs[books];
    for(int i=0;i<books;i++)
        cin>>pgs[i];
    cout<<f(pgs,books,students);
}