class Solution {
public:
    //visited 0 - unvisited
    //visited 1 - visited/ not in curr path
    //visited 2 - in curr path
    //visited -1 : unsafe
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited){

        if (visited[node] == 1) return true;
        if (visited[node] == -1) return false;
        if (visited[node] == 2) return false;

        visited[node]= 2;
        
        for(int i=0; i<graph[node].size(); i++)
        {
            int nbr = graph[node][i];
            if (visited[nbr] == 2 || visited[nbr] == -1) {
                visited[node] = -1;
                return false;
            }
            if(visited[nbr] == 0){
                if (dfs(nbr, graph, visited) == false){
                    visited[node] = -1;
                    return false;
                }
            }
        }
        visited[node] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);

        for(int i=0; i<graph.size(); i++)
        {
            if(visited[i] == 0)
            {
                if (dfs(i, graph, visited )== false){
                    visited[i]= -1;
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<visited.size(); i++){
            if(visited[i] != -1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};