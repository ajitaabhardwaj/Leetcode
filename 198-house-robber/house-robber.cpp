class Solution {
public:
    int dp(int i, vector<int>& nums, int sum, vector<int>& memo){
        if(i>=nums.size()){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int take = nums[i] + dp(i+2, nums, sum, memo);
        int skip = dp(i+1, nums, sum, memo);
        sum += max(take, skip);
        return memo[i] = sum;
    }
    int rob(vector<int>& nums) {
        int sum =0;
        vector<int> memo(nums.size(), -1);
        return dp(0, nums, sum, memo);
    }
};