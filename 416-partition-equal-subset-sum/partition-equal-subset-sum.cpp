class Solution {
public:
    int dp(int i,int target, vector<int>& nums, vector<vector<int>>& memo){
        if(target<0) return 0;
        if(i==nums.size()){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(memo[i][target] != -1) return memo[i][target];

        return memo[i][target] = dp(i+1, target-nums[i], nums, memo) or dp(i+1, target, nums, memo);        
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total+=nums[i];
        }
        if(total%2 ==1) return false;
        int target = total/2;
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1));
        int ans = dp(0, target, nums, memo);
        if(ans==0) return false;
        else return true;
    }
};