class Solution {
public:

    int dp(int i, int j, vector<int>& nums,  vector<vector<int>>& memo)
    {
        if(i==j)
        {
          memo[i][j] = nums[i];
        }

        if(memo[i][j] != -1 )
        {
            return memo[i][j];
        }

        else{
            memo[i][j] = max(
                nums[i] - dp(i+1, j, nums, memo),
                nums[j] - dp(i, j-1, nums, memo)
            );
        }
        return memo[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {

        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        if(dp(0,nums.size()-1, nums, memo) < 0){
            return false;        
        }
        else{
            return true;
        }
    }
};