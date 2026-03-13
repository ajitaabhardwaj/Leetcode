#include<queue>
#include<set>
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        vector<string> ans;
        queue<int> q;
        map<string, int> mp;
        map<int, string> mp2;
        vector<bool> visited(watchedVideos.size(), false);
        int currlevel = 0;
        visited[id] = true;
        set<int> s;
        q.push(id);
        q.push(-1);
        
        while(q.empty() != true)
        {
            if(q.front() == -1)
            {
                q.pop();
                currlevel++;
                if(q.empty() != true)
                {
                    q.push(-1);
                }
                continue;
            }
            if(currlevel == level) break;

            int curr = q.front();
            q.pop();

            for(int i=0; i<friends[curr].size(); i++)
            {   
                if(visited[friends[curr][i]] == false) 
                {
                    q.push(friends[curr][i]);
                    visited[friends[curr][i]] = true;
                }

            }
        }

        while(q.front()!=-1)
        {
            int curr = q.front();
            q.pop();
            for(int i = 0; i < watchedVideos[curr].size(); i++)
            {
                mp[watchedVideos[curr][i]]++;
            }   
        }

        for(auto &it : mp)
{
    ans.push_back(it.first);
}

sort(ans.begin(), ans.end(), [&](const string &a, const string &b)
{
    if(mp[a] != mp[b]) return mp[a] < mp[b];
    return a < b;
});

        
        return ans;
    }
};