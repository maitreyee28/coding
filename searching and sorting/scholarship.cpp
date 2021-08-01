#include<iostream>
#define ll long long
using namespace std;
bool sambhav(ll n,ll m,ll x,ll y,ll mid)
{
    return (mid*x<=(m+(n-mid)*y));
}
int main()
{
    ll n,m,x,y;
    cin>>n>>m>>x>>y;
    ll s=0;
    ll e=n;
    ll ans=0;
    while(s<=e)
    {
        ll mid=(s+e)/2;

        if(sambhav(n,m,x,y,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<ans;

}