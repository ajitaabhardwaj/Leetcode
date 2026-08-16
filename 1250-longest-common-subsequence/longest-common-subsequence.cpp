class Solution {
public:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& memo){
        if(i==s1.length() or j==s2.length()){
            return 0;
        }

        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i] == s2[j]){
            return memo[i][j] = 1 + solve(i+1, j+1, s1, s2, memo);
        }
        else{
            return  memo[i][j] = max( solve(i+1, j, s1, s2, memo), solve(i, j+1, s1, s2, memo) );
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo (text1.length(), vector<int>(text2.length(), -1) );
        return solve(0, 0, text1, text2, memo);
    }
};