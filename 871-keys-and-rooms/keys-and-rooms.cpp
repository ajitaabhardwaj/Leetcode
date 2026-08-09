class Solution {
public:
    void dfs(int node, vector<bool>& visited, unordered_map<int, vector<int>>& adj){
        if(visited[node] == true) return;
        visited[node] = true;

        for(int i=0; i<adj[node].size(); i++){
            int nbr = adj[node][i];
            if(visited[nbr] == false){
                dfs(nbr, visited, adj);
            }
        }
        return;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int, vector<int>> adj;
        

        for(int i =0; i<rooms.size(); i++){
            for(int j=0; j<rooms[i].size(); j++){
                adj[i].push_back(rooms[i][j]);
                if(adj.find(rooms[i][j]) == adj.end()){
                    adj[rooms[i][j]] = {};
                }
            }
        }

       
        vector<bool> visited(rooms.size(), false);

        dfs(0, visited, adj);

        for(int i=0; i<visited.size(); i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};