#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n,m,mod=1e9+7;
std::vector<int> v;
int dp[1000010];
int f(int x){
    if(x<0){
        return 1e18;
    }
    if(x==0){
        return 0;
    }
    if(~dp[x]){
        return dp[x];
    }
    int ans=1e18;
    for(auto u:v){
        ans=min(ans,1+f(x-u));
    }
    return dp[x]=ans;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    cout<<(f(m)!=1e18?f(m):-1)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}