class Solution {
public:
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        unordered_map<int, vector<int>>mp;
        if(n <= 1)
        {
            return true;
        }
        for(int i=0; i<edges.size(); i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(source);
        vector<bool> visited(n, false);
        visited[source] = true;

        while(q.empty() != true)
        {
            int curr = q.front();
            q.pop();
            for(int i=0; i<mp[curr].size(); i++)
            {
                if(mp[curr][i] == destination)
                {
                    return true;
                }
                if(visited[mp[curr][i]] == false)
                {
                    q.push(mp[curr][i]);
                    visited[mp[curr][i]] = true;
                }
            }

        }
        return false;
    }
};