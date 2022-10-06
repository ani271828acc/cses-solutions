#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n,mod=1e9+7;
std::vector<int> v;
int dp[1000010];
int f(int x){
    if(x<0){
        return 0;
    }
    if(x==0){
        return 1;
    }
    if(~dp[x]){
        return dp[x];
    }
    int ans=0;
    for(auto u:v){
        (ans+=f(x-u))%=mod;
    }
    return dp[x]=ans;
}
void solve(){
    cin>>n;
    for(int i=1;i<=6;i++){
        v.push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(n)<<endl;
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