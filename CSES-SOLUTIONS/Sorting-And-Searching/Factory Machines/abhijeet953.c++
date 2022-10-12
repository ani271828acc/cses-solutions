#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool fun(ll n,ll t,vector<ll>&a,ll x)
{
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=min(x/a[i],(ll)1e9);
    }
   if(sum>=t)
   return 1;
   return 0;
}

int main()
{
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)
    cin>>a[i];

    ll low=0,hi=1e18;
    while(low<hi)
    {
        ll mid =low+(hi-low)/2;
        if(fun(n,t,a,mid))
        {
            hi=mid;
        }
        else
        low =mid+1;
    }
    cout<<low<<endl;
}

