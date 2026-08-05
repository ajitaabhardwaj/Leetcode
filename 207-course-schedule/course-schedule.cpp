class Solution {
public:

    bool dfs(int node, unordered_map<int, vector<int>>& adj, set<int>& visited, set<int>& path){
        
        for(int i=0; i<adj[node].size(); i++)
        {
    
            if( visited.contains(adj[node][i])){
                if(path.contains(adj[node][i])){
                    return false;
                }
                continue;
            }
            visited.insert(adj[node][i]);
            path.insert(adj[node][i]);
            if (dfs(adj[node][i], adj, visited, path) == false){
                
                return false;
            }
            path.erase(adj[node][i]);

        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        set<int> visited {};
         set<int> path {};

        for(int i=0; i<pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        bool ans = true;
        for(auto& [key, value] : adj)
        {

            if(visited.contains(key))
            {
                continue;
            }
           
            path.insert(key);
            visited.insert(key);
            ans = dfs(key, adj, visited, path);
            if(ans == false){
                return false;

            }
            if(path.contains(key))
            {
                path.erase(key);
            }
        }
        return true;
    }
};