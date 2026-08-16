class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1, 0));
        for(int i=0; i<=n; i++) memo[n][i] =0;
        for(int i=n-1; i>=0; i--){
            for(int prev = i-1; prev>=-1; prev--){
                if(prev == -1 or nums[i]>nums[prev]){
                    memo[i][prev+1] = max( 1+ memo[i+1][i+1], memo[i+1][prev+1]);
                }
                else{
                     memo[i][prev+1] = memo[i+1][prev+1];
                }
            }
        }
        return memo[0][0];


    }
};