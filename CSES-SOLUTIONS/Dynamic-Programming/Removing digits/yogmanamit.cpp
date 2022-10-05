#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;
int dp[1000010];
int f(int x){
    if(x<=9){
        return 1;
    }
    if(~dp[x]){
        return dp[x];
    }
    std::vector<int> v;
    int y=x;
    while(y){
        v.push_back(y%10);
        y/=10;
    }
    int ans=1e18;
    for(auto u:v){
        if(u!=0)ans=min(ans,1+f(x-u));
    }
    return dp[x]=ans;
}
void solve(){
    cin>>n;
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