class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0) );
        
        dp[coins.size()][0] = 0;
        for(int j=1; j<=amount; j++){
            dp[coins.size()][j] = 1e9;
        }
        
        for(int i=coins.size()-1; i>=0; i--){
            for(int j=0; j<=amount; j++){
        
                if (j-coins[i] < 0) dp[i][j] = dp[i+1][j];
                else dp[i][j] = min ( 1+dp[i][j-coins[i]] , dp[i+1][j] );
            }
        }
        if (dp[0][amount]>=1e9) 
        {
            return -1;
        }
        else return dp[0][amount];
    }
};