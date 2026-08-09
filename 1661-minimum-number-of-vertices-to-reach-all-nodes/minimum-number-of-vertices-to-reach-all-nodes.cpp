class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            if(adj.find(edges[i][1]) == adj.end()){
                adj[edges[i][1]] = {};
            }
            indegree[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};