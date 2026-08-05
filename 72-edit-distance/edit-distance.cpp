#include <cmath>

class Solution {
public:

    int lcs(int i, int j, string& word1, string& word2, vector<vector<int>>& memo){

        if(i==word1.length() ){
            return word2.length()-j;
        }

        if(j== word2.length()){
            return word1.length()-i;
        }

        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if(word1[i] == word2[j]){
            memo[i][j] = lcs(i+1, j+1, word1, word2, memo); 
        }

        if(word1[i] != word2[j]){
            memo[i][j] = min(
              { 1+ lcs(i+1, j, word1, word2, memo), 
                1+ lcs(i, j+1, word1, word2, memo),
                1 + lcs(i+1, j+1, word1, word2, memo) }
            );
        }
        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
       
       vector<vector<int>> memo (word1.length()+1, vector<int> (word2.length()+1, -1));

        int ans = lcs(0, 0, word1, word2, memo);

       
        return ans;
    }
};