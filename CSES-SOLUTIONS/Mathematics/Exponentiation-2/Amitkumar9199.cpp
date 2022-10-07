#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
int mod=1e9+7;
inline int multiply(int a,int b){
    a%=mod;b%=mod;a=a*1ll*b;a%=mod;a+=mod;a%=mod;return a;
}
inline int power(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res=multiply(res,a);
        }
        a=multiply(a,a);
        b>>=1;
    }
    return res;
}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;while(t--)solve();return 0;
}