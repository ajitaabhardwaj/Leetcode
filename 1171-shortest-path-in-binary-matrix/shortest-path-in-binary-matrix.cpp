class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> direction{
            {-1,-1}, {0,-1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}
            };
        queue<vector<int>> q;
        

        if(grid[0][0] == 0){
            q.push({0, 0});
            visited[0][0] = true;
        }
        else{
            return -1;
        }
        q.push({-1, -1});
        int count = 1;
        while(!q.empty()){

            int curri = q.front()[0];
            int currj = q.front()[1];
            q.pop();
            if(curri == -1 and currj == -1){
                count++;
                if(!q.empty())
                    q.push({-1, -1});
                continue;
            }

            if(curri == n-1 and currj == n-1)
                return count;
  
            for(int i=0; i<direction.size(); i++){
                int nbri = curri + direction[i][0];
                int nbrj = currj + direction[i][1];

                if(nbri<0 || nbri>=n || nbrj<0 || nbrj>=n)
                    continue;

                if(grid[nbri][nbrj] == 0 && visited[nbri][nbrj] == false){
                    visited[nbri][nbrj] = true;
                    q.push({nbri, nbrj});
                }  
            }
            
            
        }
        return -1;
    }
};