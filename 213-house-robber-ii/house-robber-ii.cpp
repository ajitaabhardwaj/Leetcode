class Solution {
public:
   
    int dp(int i, vector<int>& nums, vector<int>& memo, int last){

        if(i>last) return 0;
        if(memo[i] != -1) return memo[i];
        return memo[i] = max(dp(i+1, nums, memo, last), nums[i] + dp(i+2, nums, memo, last));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> memo1(nums.size(), -1);
        vector<int> memo2(nums.size(), -1);
        int opt1 = dp(0, nums, memo1, nums.size()-2);
        int opt2 = dp(1, nums, memo2, nums.size()-1);
        return max(opt1, opt2);
    }
};