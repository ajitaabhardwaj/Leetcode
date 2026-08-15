class Solution {
public:
    int dp(int i, vector<int>&cost, vector<int>& memo){
        if(i>=cost.size()) return 0;
        if(memo[i] != -1) return memo[i];
        return memo[i] = cost[i] + min(dp(i+1, cost, memo),dp(i+2, cost, memo));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, -1);
        return min(dp(0, cost, memo), dp(1, cost, memo));

    }
};