class Solution {
  
     bool bfs( vector<vector<int>> &adj,vector<int> &color,int node)
    {
        queue<int> q;
        q.push(node);
        color[node]=1;
        
        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            
            for(auto i:adj[parent])
            {
                if(color[i]==color[parent])
                    return false;
                
                if(color[i]==-1)
                {
                    q.push(i);
                    color[i]=1-color[parent];
                }              
            }            
        }
        return 1;  
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n+1); 
        vector<int> color(n+1,-1);     
     
        for(auto i:dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);            
        }
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
                if(!bfs(adj,color,i))
                   return 0;
        }
        return true;
    }       
};
