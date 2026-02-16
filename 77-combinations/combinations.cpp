class Solution {
public:

    void solve(int n, int k, int i, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(curr.size() == k)
        {
            ans.push_back(curr);
            return;
        }

        if(i == n+1)
        {
            return;
        }

        curr.push_back(i);
        solve(n, k, i+1, curr, ans);
        curr.pop_back();
        solve(n, k, i+1, curr, ans);

        return;

    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        int i=1;
        solve(n, k, i, curr, ans);
        return ans;
    }
};