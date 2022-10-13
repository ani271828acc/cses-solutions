#include <bits/stdc++.h>
 
using namespace std;
#define ll              long long
#define vll             vector<ll>
#define pb              push_back
#define endl            "\n" 

const ll i1     =    2e5+5;

ll n;
vll adj[i1];
set<ll> colors[i1];
ll cont[i1];
 
void dfs(ll curr, ll parent) {
 
    for( auto child : adj[curr] ){
        if(child != parent){
            dfs(child, curr);
 
            if(colors[curr].size() < colors[child].size()){
                swap(colors[curr], colors[child]);
            }
 
            for(auto color : colors[child]){
                colors[curr].insert(color);
            }
        }
    }
 
    cont[curr] = colors[curr].size();
 
}
 
 
void solve(ll test_case){
 
    cin>>n;

    for( int i = 1; i < n + 1; i++ ){
        ll x; cin>>x;
        colors[i].insert(x);
    }

    for( int i = 0; i < n - 1; i++ ){
        ll u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    dfs(1, -1);

    for( int i = 1; i < n + 1; i++ ){
        cout << cont[i] << " ";
    }
    cout << endl;
 
}

int main(){
 
    ll ttcc = 1;
    ll test_case=1;
    while(ttcc--){
        solve(test_case);
        test_case++;
    }
}
