#include <climits>
class Solution {
public:

    long long int sol(int i, int remamount, vector<int>& coins, vector<vector<int>>& memo)
    {
        if(i==coins.size() || remamount<0 ){
            return 1e9;
        }

        if(memo[i][remamount] != -1){
            return memo[i][remamount];
        }

        if(remamount == 0){
            return 0;
        }
        
        memo[i][remamount] =  min( 
            sol(i+1, remamount, coins, memo), 
            1+ sol(i, remamount-coins[i], coins, memo)
            );
        
        return memo[i][remamount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size()+1, vector<int>(amount+1, -1));

        long long int ans = sol(0, amount, coins, memo);
        return (ans < 1e9) ? ans: -1; 
     
    }
};