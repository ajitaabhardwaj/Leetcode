class Solution {
public:
    bool dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        if(visited[i][j] == true) return false;
        if(i == grid.size()-1 or i==0 or j == grid[0].size()-1 or j==0 ){
            if(grid[i][j] == 0){
                return false;
            }
        }
        visited[i][j] = true;
        bool flag = true;
        vector<vector<int>> steps = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        for(auto step : steps){
            int nbi = step[0]+i;
            int nbj = step[1]+j;
            if(nbi<0 or nbi>=grid.size() or nbj<0 or nbj>=grid[0].size()){
                continue;
            }
            if(grid[nbi][nbj] == 0 and visited[nbi][nbj] == false){
                if (!dfs(nbi, nbj, visited, grid)) flag = false;
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       
        vector<vector<bool>> visited( grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0; i<=grid.size()-1; i++){
            for(int j=0; j<=grid[0].size()-1; j++){
                if(grid[i][j] == 0 and visited[i][j] == false){
                    if (dfs(i, j, visited, grid)) ans++;
                }
            }
        }
        return ans;
    }
};