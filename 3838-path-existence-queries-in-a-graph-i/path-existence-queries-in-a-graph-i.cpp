class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> mp(n);
        int x = 0;
        mp[0] = 0;
            for(int i=1; i<n; i++)
            {
                if(nums[i]-nums[i-1] > maxDiff)
                {
                    x++;
                }
                mp[i] = x;
            }
            
        for(int q=0; q<queries.size(); q++)
        {
            int src = queries[q][0];
            int dest = queries[q][1];
            
            if(mp[src] == mp[dest])
            {
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
    return ans;
}
};