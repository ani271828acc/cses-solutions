#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
 
int main()
{
	int n,m,a,b; cin >> n >> m;
    vector <int> adj[n+1];
    int indegree[n+1] = {};
    while(m--){
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    int dp[n+1] = {};
    dp[1] = 1;
    queue <int> q;
 
    for(int i = 0; i<n; i++){
        if(indegree[i+1]==0){q.push(i+1);}
    }
 
    while(q.size()){
        int i = q.front(); q.pop();
        for(auto x:adj[i]){
            indegree[x]--;
            dp[x] += dp[i];
            dp[x] %= mod;
            if(indegree[x]==0){q.push(x);}
        }
    }
 
    cout << dp[n] << endl;
 
	return 0;
}
