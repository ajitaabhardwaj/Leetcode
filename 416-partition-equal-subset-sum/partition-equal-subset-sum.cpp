class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total+=nums[i];
        }
        if(total%2 ==1) return false;
        int target = total/2;
        vector<vector<int>> memo(nums.size()+1, vector<int>(target+1, 0));
        memo[nums.size()][0] = 1;
        for(int i=nums.size()-1; i>=0; i--){
            for(int j=target; j>0; j--){
                if(nums[i]>j) memo[i][j] = memo[i+1][j];
                else{
                    memo[i][j] = memo[i+1][j-nums[i]] || memo[i+1][j];
                }
            }
        }
        return memo[0][target];
    }
};