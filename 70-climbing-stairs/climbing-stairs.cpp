class Solution {
public:

    unordered_map<int, int> memo { {0,0}, {1,1}, {2,2}};
    int climbStairs(int n) {

        if(memo.find(n) != memo.end()){
            return memo[n];
        }

        if(n<=2)
        {
            return n;
        }

        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];

    return climbStairs(n);
    }
};