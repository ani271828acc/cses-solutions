#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mat[1000001][2];
ll mod=1e9+7;


void precompute()
{
    mat[1][0]=1;
    mat[1][1]=1;
    for(ll i=2;i<=1000000;i++)
    {
        mat[i][0] = ((mat[i-1][0]*4)%mod + mat[i-1][1])%mod;
        mat[i][1] = ((mat[i-1][1]*2)%mod + mat[i-1][0])%mod;
    }
}

int main()
{
    
    ll t;
    cin>>t;
    precompute();
    while(t--)
    {
        ll n;
        cin>>n;
        
        cout<<(mat[n][0]+mat[n][1])%mod<<endl;
    }
}

