#include <cmath>
class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue< vector<int>,
            vector<vector<int>>,
            greater <vector<int>> >pq;
        
        vector<vector<int>> next {{-1,0}, {0, -1}, {1,0}, {0,1}};
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while(!pq.empty()){
            int curreffort = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];

            pq.pop();
            if(curreffort > dist[i][j]) continue;

            if(i==m-1 and j==n-1) return curreffort;

            for(int x=0; x<next.size(); x++){
            
                int nbri = i+next[x][0];
                int nbrj = j+next[x][1];
                if(nbri <0 or nbri >= m or nbrj <0 or nbrj >= n) continue;

                int edge = abs(heights[i][j] - heights[nbri][nbrj]);
                int neweffort = max(curreffort, edge);

                if(neweffort < dist[nbri][nbrj]){
                    dist[nbri][nbrj] = neweffort;
                    pq.push({neweffort, nbri, nbrj});
                }
            }
        }
        return 0;
    }
};