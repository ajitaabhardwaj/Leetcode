class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        if(visited[node] == true) return;

        visited[node] = true;
        for(int i=0; i<adj[node].size(); i++){
            if(visited[adj[node][i]] == false){
                dfs(adj[node][i], adj, visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<isConnected.size();i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for(int i=0; i<visited.size(); i++)
        {
            if(visited[i] == false){
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;

    }
};