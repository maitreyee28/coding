#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {1, 2, 3, 4, -10};
    int n=5;
    int sum=0;
    int abtak=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum<0)
            sum=0;
        abtak=max(abtak,sum);
    }
    cout<<abtak;
}