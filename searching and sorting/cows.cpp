#include<bits/stdc++.h>
using namespace std;
bool check(int a[],int stands,int cows,int mid){
    sort(a,a+stands);
    int cnt=1;
    int prev=a[0];
    for(int i=1;i<stands;i++){
        if(a[i] - prev >= mid){
            cnt++;
            prev=a[i];
            if(cnt == cows){
                return true;
            }
        }
    }
    if(cnt >= cows) return true;
    return false;
}
int f(int a[],int stands,int cows){
    int s=0;
    sort(a,a+stands);
    int e= a[stands - 1] - a[0];
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(check(a,stands,cows,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int stands,cows;
        cin>>stands>>cows;
        int a[stands];
        for(int i=0;i<stands;i++)
            cin>>a[i];
        
        cout<<f(a,stands,cows);

    }
   
}