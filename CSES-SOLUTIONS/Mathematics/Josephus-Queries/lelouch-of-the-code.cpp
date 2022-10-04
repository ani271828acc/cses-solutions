#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll modulo(ll n,ll x) {
    while(n <= 0)
        n+=x;
    if(n == x)
        return n;
    else
        return n%x;
}
 
ll get(ll n,ll k){
    ll diff=1,start=2,len=n;
    bool first=false;
    while(len){
        ll del=len/2+(first&&len%2);
        if(k<=del)
            return modulo(start + 2*(k-1)*diff, n);
        if(len%2)
            start=modulo(start+(first?3:-1)*diff,n);
        else 
            start=modulo(start+diff,n);
        diff*=2;
        if(len%2)
            first = !first;
        k -= del;
        len -= del;
    }
    return start;
}
 
void josephus_queries() {
    ll n,k;
    cin>>n>>k;
    cout<<get(n,k)<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int32_t tc=1;
    cin>>tc;
    while(tc--){
        josephus_queries();
    }
}