#include <algorithm>
class Solution {
public:

    void dijkstra(int src,  unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& dist){

        priority_queue< pair<int, int>, 
            vector <pair<int, int>>, 
            greater <pair<int,int>> >pq;

        pq.push({0, src});

        while(!pq.empty()){
            int distu = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            if(distu > dist[u]){
                continue;
            }

            for(auto& [v, distuv]: adj[u]){
                if(dist[v] > dist[u] + distuv){
                    dist[v] = dist[u] + distuv;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for(int i=0; i<times.size(); i++){
            int s = times[i][0];
            adj[s].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n+1, INT_MAX);
        
        dist[k] = 0;
        dijkstra(k, adj, dist);
        int ans = 0;
        for(int i=1; i<dist.size(); i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        
        return ans;
        
    }
};