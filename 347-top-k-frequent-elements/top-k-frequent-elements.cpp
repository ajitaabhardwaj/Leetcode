class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]]++;
            }
        }

        for(auto it = mp.begin(); it!= mp.end(); it++)
        {
            pq.push({it->second, it->first});
        }

        while(k>0)
        {
            auto x = pq.top();
            ans.push_back(x.second);
            pq.pop();
            k--;
        }
        return ans;
    }
};