class Solution {
public:

    bool dfs(int node, vector<bool> &visited, unordered_map<int, vector<int>>& adj,  unordered_map<int, bool>&possible)
    {
        if(possible[node] == true)
        {
            
            return true;
        }

        unordered_map<int, bool>poss;
        
        for(int i=0; i<adj[node].size(); i++)
        {
            int nbr = adj[node][i];
            
            if(possible[nbr] == true)
            {
                poss[nbr] = true;
            }
            else{
                poss[nbr] = false;
            }
                
            if(visited[nbr] == false)
            {
                
                visited[nbr] = true;
                if (dfs(nbr, visited, adj, possible) == true)
                {
                    possible[nbr] = true;
                    poss[nbr] = true;
                }
            }
        }
        for(auto& [key, value] : poss)
        {
            if(poss[key] == false)
            {
                
                return false;
            }
        }
        possible[node] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {  
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> possible;
        for (int i=0; i<prerequisites.size(); i++)
        {
            if(prerequisites[i][0] == prerequisites[i][1])
            {
                return false;
            }
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            possible[prerequisites[i][1]] = true;
        }
        
        
        for(auto& [key, value] : adj)
        {
            possible[key] = false;
        }
        
        
        vector<bool> visited(numCourses, false);

        for (auto& [i, value] : possible)
        {
            if(possible[i] == false)
            {
                visited[i] = true;
                possible[i] = dfs(i, visited, adj, possible);
               
            }
            if(possible[i] == false)
            {
                
                return false;
            }
        }
        return true;
    }
};