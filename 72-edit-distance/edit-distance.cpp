class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        for(int j = 0; j<=n; j++) memo[m][j] = word2.length()-j;
        for(int i = 0; i<=m; i++) memo[i][n] = word1.length()-i;

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    memo[i][j] = memo[i+1][j+1];
                }
                else{
                    memo[i][j] = 1+ min({ memo[i+1][j+1], memo[i+1][j], memo[i][j+1] });
                }
            }
        }
        return memo[0][0];
    }
};