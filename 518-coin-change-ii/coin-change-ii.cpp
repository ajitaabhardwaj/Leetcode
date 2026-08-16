class Solution {
public:

    int dp(int i, int rem, vector<int>&coins, vector<vector<int>>& memo){
        if(rem == 0) {
            return 1;
        }
        if(i==coins.size()) return 0;
        if(rem<0) return 0;

        if(memo[i][rem]!=-1) return memo[i][rem];

        int op1 = dp(i, rem-coins[i], coins, memo);
        int op2 = dp(i+1, rem, coins, memo);

        return memo[i][rem] = op1 + op2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        int ans = dp(0, amount, coins, memo);
        return ans;
    }
};