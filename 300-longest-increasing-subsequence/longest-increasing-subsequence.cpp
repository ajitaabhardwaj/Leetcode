class Solution {
public:
    //i
    // take - make it as prev (this > prev)
    // dont take
    int dp(int i, int prev, vector<int>& nums, vector<vector<int>>& memo){
        if(i>=nums.size()) 
            return 0;

        if(memo[i][prev+1] != -1) 
            return memo[i][prev+1];

        int op1 = dp(i+1, prev, nums, memo);
        int op2 = 0;
        if (prev==-1 or nums[i]>nums[prev])
            op2 = 1 + dp(i+1, i, nums, memo);

        return memo[i][prev+1] = max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size()+1, vector<int>(nums.size()+1, -1));
        int ans = dp(0, -1, nums, memo);
        return ans;
    }
};