#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        e[u-1].push_back(v-1);
    }
    vector<int> vis(n,0),prev(n,-1);
    auto dfs=[&](int cur,auto &&dfs)->void{
        vis[cur]=1;
        for(auto node:e[cur]) {
            if(vis[node]==1) {
                vector<int> res;
                int cc=cur;
                while(cc!=node) {
                    res.push_back(cc);
                    cc=prev[cc];
                }
                res.push_back(node);
                res.push_back(cur);
                reverse(res.begin(),res.end());
                cout<<res.size()<<"\n";
                for(auto cc:res)
                    cout<<cc+1<<" ";
                exit(0);
            } else if(!vis[node]) {
                prev[node]=cur;
                dfs(node,dfs);
            }
        }
        vis[cur]=2;
    };
 
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(i,dfs);
        }
    }
 
    cout<<"IMPOSSIBLE\n";
}