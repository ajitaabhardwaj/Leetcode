class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>& sums)
    {
        if(i == nums.size()-1 || i == nums.size()-2)
        {
            sums[i] = nums[i];
            return sums[i];
        }
        if(i>=nums.size())
        {
            return 0;
        }
        if(sums[i] != -1)
        {
            return sums[i];
        }
        sums[i] = max(solve(i+2, nums, sums) + nums[i], solve(i+3, nums, sums) + nums[i]);
        return sums[i];
    }

    int rob(vector<int>& nums) 
    {
        vector<int> sums (nums.size(), -1);
        int ans = 0;
        if(nums.size() ==2)
        {
            return max(nums[0], nums[1]);
        }

        if(nums.size() <=1)
        {
            return nums[0];
        }
        return max(solve(0, nums, sums), solve(1, nums, sums));
    }
};