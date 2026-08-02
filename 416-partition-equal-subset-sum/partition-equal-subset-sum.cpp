class Solution {
public:

    int memo(int i, int total, vector<int>& nums,  vector<vector<int>>& dp){
        if(total == 0){
            return 1;
        }
        if(i==nums.size()){
            return 0;
        }
        if(total<0){
            return 0;
        }

        if(dp[i][total] != -1)
        {
            return dp[i][total];
        }

        
        dp[i][total] = ( memo(i+1, total, nums, dp) || memo(i+1, total-nums[i], nums, dp) );
        return  dp[i][total];
        
    }


    bool canPartition(vector<int>& nums) 
    {
        int total = 0;

        for(int i=0; i<nums.size(); i++)
        {
            total+=nums[i];
        }
        if(total%2 !=0)
        {
            return false;
        }
        total = total/2;

        vector<vector<int>> dp(nums.size()+1, vector<int> (total+1, -1));

        if (memo(0, total, nums, dp) == 0)
        {
            return false;
        }
        else{
            return true;
        }
    }
};