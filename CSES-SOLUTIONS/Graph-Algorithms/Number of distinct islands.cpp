class Solution {
  public:
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    char dir[4]={'U','R','D','L'};
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        set<string> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    string curr="";
                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty())
                    {
                        int x=q.front().first,y=q.front().second;
                        q.pop();
                        for(int idx=0;idx<4;idx++)
                        {
                            int nx=x+dx[idx];
                            int ny=y+dy[idx];
                            if(nx>=0 && ny>=0 && ny<m && nx<n && grid[nx][ny]==1)
                            {
                                grid[nx][ny]=0;
                                q.push({nx,ny});
                                curr.push_back(dir[idx]);
                            }
                            else
                                curr.push_back('E');
                        }
                    }
                    st.insert(curr);
                }
            }
        }
        return st.size();
    }
};
