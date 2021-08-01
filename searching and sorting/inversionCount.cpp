#include<bits/stdc++.h>
using namespace std;
int mer(int *a,int s,int e)
{   
    int cnt=0;
    int mid=(s+e)/2;
    int t[100];
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(a[i]<=a[j])
            t[k++]=a[i++];
        else{
            t[k++]=a[j++];
            cnt+= mid-i;
        }

    }
    while(i<=mid)
        t[k++]=a[i++];
    while(j<=e)
        t[k++]=a[j++];
    for(int r=s;r<=e;r++)
        a[r]=t[r];
    return cnt;
}
int ms(int a[],int s,int e)
{
    int cnt=0;
    if(s<e){
        int mid=(s+e)/2;
        cnt+= ms(a,s,mid);
        cnt+= ms(a,mid+1,e);
        cnt+= mer(a,s,e);
    }
    return cnt;
}
int main()
{
    int a[]={ 1, 20, 6, 4, 5 };
    int n=sizeof(a)/sizeof(int);
    cout<<ms(a,0,n-1);
    // for(int i=0;i<n;i++)
    //     cout<<a[i];

}
