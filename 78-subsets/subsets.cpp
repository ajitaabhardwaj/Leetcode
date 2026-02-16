class Solution {
public:
    void solve(int i, vector<int> curr, vector<int> nums, vector<vector<int>>& ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(curr);
            return;
        }
        solve(i+1, curr, nums, ans);
        curr.push_back(nums[i]);
        solve(i+1, curr, nums, ans);
        curr.pop_back();
        return;
        
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        int i=0;
        solve(i, curr, nums, ans);
        return ans;
    }
};