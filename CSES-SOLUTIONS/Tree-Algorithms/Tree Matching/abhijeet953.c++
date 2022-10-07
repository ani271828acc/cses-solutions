#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
vector<vector<int>> adj;
vector<int>vis;int ans=0;
 
void dfs(int node,int par)
{
    for(int child:adj[node])
    {
        if(child!=par)
        {
            dfs(child,node);
            if(vis[child]==0 and vis[node]==0)
            {
                vis[child]=vis[node]=1;ans++;
            }
        }
    }
}
 
int main()
{
    int n;
    cin>>n;
    adj.resize(n+1);vis.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<endl;
}