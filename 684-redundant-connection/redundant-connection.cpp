class Solution {
public:
    void dfs(int node, int parent, vector<bool>& visited, unordered_map<int, vector<int>>& adj, vector<int>& ans)
    {
        if(ans[0] != -1 && ans[1] != -1)
        {
            return;
        }
        for(int i=0; i<adj[node].size(); i++)
        {
            
            if(adj[node][i] ==  parent)
            {
                ans[0] = node;
                ans[1] = parent;
                return;
            }
            if(visited[adj[node][i]] == false)
            {
                visited[adj[node][i]] = true;
                dfs(adj[node][i], parent, visited, adj, ans);
            }
        }
        return;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> adj;
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        for(int i=0; i<edges.size(); i++)
        {
            vector<bool> visited(edges.size()+1, false);
            visited[edges[i][0]] = true;
            dfs(edges[i][0], edges[i][1], visited, adj, ans);

            if(ans[0] != -1 && ans[1] != -1)
            {
                return edges[i];
            }
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return ans;
    }
}; 