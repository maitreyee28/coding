#include<bits/stdc++.h>
using namespace std;

int f(vector<int> a)
{
    int n = a.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum+a[i];
    }

    if(sum%3!=0){
        return 0;
    }
    int first = sum/3;
    int second = first*2;
    int occFirst=0,occSecond=0;
    sum=0;
    int flag=1;
    int ans=0;
    for(int i=0;i<n;i++){
        sum+=a[i];

        if(sum==first && i<n-2){
            occFirst=1;
            int j=i+1;
            int sum2 = first;
            occSecond=0;
            while(j<n-1){
                sum2 = sum2+a[j];
                if(sum2==second)
                    occSecond++;
                j++;
            }
            ans = ans+(occSecond);
            cout<<a[i]<<" "<<occFirst<<" "<<occSecond<<endl;

        }
        //if(sum==second && i<n-1 && i>0 && i>=prev)
          //  occSecond++;
        //cout<<a[i]<<" "<<occFirst<<" "<<occSecond<<endl;
    }
    return ans;

}


int main()
{
    //vector<int> a = {2,7,0,0,5,3,1,0,4,2,3};
    vector<int> a = {0,1,-1,0,0,0,0};
    cout<<f(a);
}
