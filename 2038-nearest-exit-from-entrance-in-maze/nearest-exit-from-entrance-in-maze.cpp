class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> steps { {-1, 0}, {0, -1}, {1,0}, {0,1} };
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        int ans=0;

        q.push(entrance);
        visited[entrance[0]][entrance[1]] = true;
        while(!q.empty()){

            int sz= q.size();

        for(int que=0; que<sz; que++){
            int i = q.front()[0];
            int j = q.front()[1];
            q.pop();
            for(auto& step: steps){

                int nbi = i + step[0];
                int nbj = j + step[1];

                if(nbi<0 or nbi>=m or nbj<0 or nbj>=n){
                    continue;
                }
                
                if(maze[nbi][nbj] == '.' and visited[nbi][nbj] == false){

                    if(nbi == 0 or nbj == 0 or nbi == m-1 or nbj == n-1 ){
                    return ++ans;
                    }
                    visited[nbi][nbj] = true;
                    q.push({nbi, nbj});
                }
            }
        }
        ans++;
            
        }
        return -1;
        
    }
};
