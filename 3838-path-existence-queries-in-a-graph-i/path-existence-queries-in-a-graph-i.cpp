class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int, int> mp;
        mp[0] = 0;
        int a = 0;
            for(int i=1; i<n; i++)
            {
                if(nums[i]-nums[i-1] <= maxDiff)
                {
                    mp[a] = i;
                }
                else{
                    a = i;
                }
            }

        for(int q=0; q<queries.size(); q++)
        {
            int src = queries[q][0];
            int dest = queries[q][1];
            if(src == dest)
            {
                ans.push_back(true);
                continue;
            }
            int s;
            int d = dest;
            if(src<=dest)
            {
                s = src;
            }
            else{
                s = dest;
                d = src;
            }

            int flag =0;
            for(auto& [key, value] : mp)
            {
                if(s >= key && d <= value)
                {
                    flag =1;
                    ans.push_back(true);
                    break;
                }
            }

            if(flag == 0)
            {
                ans.push_back(false);
            }
        }
    return ans;
}
};