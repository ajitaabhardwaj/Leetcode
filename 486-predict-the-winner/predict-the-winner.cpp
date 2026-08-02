class Solution {
public:

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(nums.size()+1, vector<int>(nums.size()+1, 0));

        for(int i=n-1; i>=0; i--)
        {
            for (int j=i; j<n; j++)
            {
                if(i==j)
                {
                    memo[i][j] = nums[i];
                }
                else{
                    memo[i][j] = max(nums[j] - memo[i][j-1], nums[i] - memo[i+1][j]);
                }
            }
        }   

        if( memo[0][n-1]< 0){
            return false;
        } 
        else{
            return true;
        }

    }
};