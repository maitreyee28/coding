#include<bits/stdc++.h>
using namespace std;

int* union(int a[],int b[],int n,int m)
{
    /* data */
    int ans[10];
    int i=0;
    int j=0;
    int k=0;
    while(i<n && j<m){
        if(a[i]!=b[j])
        {
            ans[k++]=a[i++];
            ans[k++]=b[j++]
        }

        else{
            ans[k++]=a[i++];
            j++;
        }
    }
    return ans;
};


int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int m;
    cin>>m;
    int b[100];
    for(int i=0;i<m;i++)
        cin>>b[i];
    
    int* ans=union(a,b,n,m);

    for()
 
}