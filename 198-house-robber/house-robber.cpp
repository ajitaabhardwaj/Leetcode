class Solution {
public:
   
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(nums.size()+1, -1);
        memo[n] = 0;
        memo[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            memo[i] = max((memo[i+2]+nums[i]), memo[i+1]);
        }
        return memo[0];
    }
};