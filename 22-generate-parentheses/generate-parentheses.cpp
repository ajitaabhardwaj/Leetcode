class Solution {
public:

    void solve(int n, int left, int right, string& curr, vector<string>& ans) 
    {
        if(left == n && right == n)
        {
            ans.push_back(curr);
            return;
        }
        if(left > n)
        {
            return;
        }
        if(right > left )
        {
            return;
        }
        curr.push_back('(');
        solve(n, left+1, right, curr, ans);
        curr.pop_back();
        curr.push_back(')');
        solve(n, left, right+1, curr, ans);
        curr.pop_back();
        return;

    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        string curr = "";
        int left = 0;
        int right = 0;
        curr.push_back('(');
        solve(n, 1, 0, curr, ans);
        return ans;

    }
};