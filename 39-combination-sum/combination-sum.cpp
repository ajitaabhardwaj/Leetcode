class Solution {
public:
    void solve(int i, vector<int>& currans, int remaining, vector<int>& candidates, int target,vector<vector<int>>& ans)
    {
        if(remaining == 0)
        {
            ans.push_back(currans);
            return;
        }
        
        if(i==candidates.size() || remaining < 0)
        {
            return;
        }

        solve(i+1, currans, remaining, candidates, target, ans);

        currans.push_back(candidates[i]);
        remaining = remaining-candidates[i];
        solve(i, currans, remaining, candidates, target, ans);
        currans.pop_back();
        remaining = remaining+candidates[i];
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> currans;
        int remaining = target;
        solve(0, currans, remaining, candidates, target, ans);
        return ans;
    }
};