class Solution {
public:                                                                                                                                                                

    int dp(int i, int m, int n,  vector<vector<vector<int>>>& memo, vector<string>& strs){
        if(i == strs.size()){
            return 0;
        }
        if(memo[i][m][n] != -1)
        {
            return memo[i][m][n];
        }

        int one = 0;
        int zero = 0;
        for (int x = 0; x<strs[i].length(); x++){
            if(strs[i][x] == '1'){
                one++;
            }
            else{
                zero++;
            }
        }
        if(m-zero <0|| n-one<0){
           memo[i][m][n] = dp(i+1, m, n, memo, strs);
        }
        else{
            memo[i][m][n] = max(
            1 + dp(i+1, m-zero, n-one, memo, strs),
            dp(i+1, m, n, memo, strs)
            );
        }
        return memo[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return dp(0, m, n, memo, strs);
    }
};