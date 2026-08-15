class Solution {
public:
    //string - int(s) <0 or >26 ignore
    //add char , i++;
    //number of ways.
    int dp(int i, string&s, vector<int>& memo){
       
        if(i==s.length()) return 1;
        if (s[i] == '0') return 0;
        if(memo[i] != -1) return memo[i];
        
        int op1 = dp(i+1, s, memo);
        int op2 = 0;
        if(i+1 <s.length()) {
            int num = (s[i] - '0')*10 + (s[i+1] - '0');
            if(num!=0 and num<=26){
               op2 = dp(i+2, s, memo);
            }

        }       
        
        return memo[i] = op1+op2;
    }
    int numDecodings(string s) {
        vector<int>memo (s.length()+1, -1);
        return dp(0, s, memo);
    }
};