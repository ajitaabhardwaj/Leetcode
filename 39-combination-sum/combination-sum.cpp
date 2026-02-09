class Solution {
public:
    void solve(int i, vector<int>& currans, int currtotal, vector<int>& candidates, int target,vector<vector<int>>& ans)
    {
        if(currtotal == target)
        {
            ans.push_back(currans);
            return;
        }
        
        if(i==candidates.size() || currtotal > target)
        {
            return;
        }

        solve(i+1, currans, currtotal, candidates, target, ans);

        currans.push_back(candidates[i]);
        currtotal = currtotal+candidates[i];
        solve(i, currans, currtotal, candidates, target, ans);
        currans.pop_back();
        currtotal = currtotal-candidates[i];
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> currans;
        int currtotal = 0;
        solve(0, currans, currtotal, candidates, target, ans);
        return ans;
    }
};