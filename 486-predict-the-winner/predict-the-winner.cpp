class Solution {
public:
    int dp(vector<vector<int>>& memo, vector<int>& nums, int i, int j)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            memo[i][j] = nums[i];
            return memo[i][j];
        }
        if( memo[i][j] != -1)
        {
            return memo[i][j];
        }

        memo[i][j] = max
        (nums[i] - dp(memo, nums, i+1, j), 
        nums[j] - dp(memo, nums, i, j-1));
        return memo[i][j];
    }
    
    bool predictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n ,-1));
        int ans = dp(memo, nums, 0, n-1);
        if(ans>=0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};