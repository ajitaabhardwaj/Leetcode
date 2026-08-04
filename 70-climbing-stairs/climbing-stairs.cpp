class Solution {
public:
    int sol(int n, vector<int>& memo){
        if(n<0){
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        memo[n] = sol(n-1, memo) + sol(n-2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        vector<int> memo(n+1, -1);

        memo[0]= 0;
        return sol(n, memo);
    }
};