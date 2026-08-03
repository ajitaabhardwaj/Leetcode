class Solution {
public:
    int dp(int i, int sum1, int sum2, int target, vector<int>& nums){
        
        if(sum1-sum2 == target && i==nums.size()){
            return 1;
        }
        if(i==nums.size()){
            return 0;
        }
        return dp(i+1, sum1+nums[i], sum2, target, nums) + dp(i+1, sum1, sum2+nums[i],target, nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(0, 0, 0,target, nums);

    }
};