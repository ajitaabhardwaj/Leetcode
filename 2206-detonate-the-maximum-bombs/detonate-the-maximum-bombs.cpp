class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<bombs.size(); i++)
        {
            for(int j=i+1; j<bombs.size(); j++)
            {
                double xDiff = std::abs(bombs[j][0] - bombs[i][0]);
                double yDiff = std::abs(bombs[j][1] - bombs[i][1]);
                double dist = hypot(xDiff, yDiff);

                if(dist <= bombs[j][2])
                {
                    mp[j].push_back(i);
                }
                if(dist <= bombs[i][2])
                {
                    mp[i].push_back(j);
                }
            }   
        }
        for(int i=0; i<bombs.size(); i++)
        {
            if(mp.find(i) == mp.end())
            {
                mp[i]= {};
            }
        }

        int max_nodes = 0;
        for(const auto& [key, val] : mp)
        {
            queue<int> q;
            vector<bool> visited(bombs.size(), false);
            int nodes = 0;
            q.push(key);
            visited[key] = true;
            while(q.empty() != true)
            {
                int curr = q.front();
                q.pop();
                nodes++;
                for(int i=0; i<mp[curr].size(); i++)
                {
                    if(visited[mp[curr][i]] == false)
                    {
                        visited[mp[curr][i]] = true;
                        q.push(mp[curr][i]);
                    }
                }
            }
            max_nodes = std::max(max_nodes, nodes);
        }
        return max_nodes;
    }
};