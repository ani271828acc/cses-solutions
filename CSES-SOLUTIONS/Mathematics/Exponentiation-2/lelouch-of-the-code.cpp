#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll m420=1e9+7;
 
ll modp(ll base,ll exp,ll mod) {
    ll res=1;
    while(exp) {
        if(exp%2)
            res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}
 
void exponentiation2() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll y=modp(b,c,m420-1);
    cout<<modp(a,y,m420)<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t tc=1;
    cin>>tc;
    while(tc--){
        exponentiation2();
    }
}