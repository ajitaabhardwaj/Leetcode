class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        queue<int> q;
        for(int i=0; i<pre.size(); i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
            if(indegree.find(v) == indegree.end()){
                //not found
                indegree[v] = 1;
            }
            else{
                indegree[v]++;
            }
            if(indegree.find(u) == indegree.end()){
                indegree[u] = 0;
            }
        }

        for(auto& [key, value] : indegree){
            if (value == 0)
            {
                q.push(key);
            }
        }
        //bfs
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int i=0 ;i <adj[node].size(); i++)
            {
                int nbr = adj[node][i];
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        for(auto& [key, value]:indegree){
            if(value!=0){
                return false;
            }
        }
        return true;
    }
};