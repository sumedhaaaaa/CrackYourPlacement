class Solution {
public:
    vector<pair<int,int>>direction{{-1,0},{1,0},{0,-1},{0,1}};
    
    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1')
            return ;
        
        grid[i][j]='$';
        
        for(pair<int,int> &p:direction)
        {
            int i1=i+p.first;
            int j1=j+p.second;
            dfs(grid,i1,j1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                        c++;
                }
            }
        }
        return c;
        
    }
};
