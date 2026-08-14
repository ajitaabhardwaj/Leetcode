class Solution {
public:
    int dp(int i, vector<int>& nums, vector<int>& memo){
        if(i>=nums.size()-1) return 0;
        if(memo[i] != -1) return memo[i];
        
        int jump = nums[i];
        int mini = INT_MAX;
        for(int j=1; j<=jump; j++){
            int nextjump = dp(i+j, nums, memo);
            if(nextjump != INT_MAX) mini = min(mini, 1+nextjump);
        }
        return memo[i] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        return dp(0, nums, memo);


    }
};