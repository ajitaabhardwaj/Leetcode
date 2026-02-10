class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            int rem = target-nums[i];
            if(seen.find(rem) != seen.end())
            {
                ans.push_back(seen[rem]);
                ans.push_back(i);
                break;
            }
            seen[nums[i]] = i;
        }
        return ans;
    }
};