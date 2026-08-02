class Solution {
public:

    bool dfs(int node, int dest, vector<bool>& visited, unordered_map<int, vector<int>>& adj)
    {
        if(node == dest)
        {
            return true;
        }

        for(int i=0; i<adj[node].size(); i++)
        {
            if(visited[adj[node][i]] == false)
            {
                visited[adj[node][i]] = true;
                if (dfs(adj[node][i], dest, visited, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n, false);
        visited[source] = true;

        return dfs(source, destination, visited, adj);
       }
};