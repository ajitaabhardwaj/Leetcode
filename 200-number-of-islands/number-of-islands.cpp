class Solution {
public:
    
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>&visited)
    {
        if(visited[i][j] == true)
        {
            return;
        }
        visited[i][j] = true;

        if(grid[i][j] == '0')
        {
            return;
        }
        if(j+1 < m) dfs(i, j+1, n, m, grid,visited);
        if(j-1 >= 0) dfs(i, j-1, n, m, grid,visited);
        if(i-1 >= 0) dfs(i-1, j, n, m, grid,visited);
        if(i+1 < n) dfs(i+1, j, n, m, grid,visited);

        return;
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        int count =0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == false)
                {
                    dfs(i, j, n, m, grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};