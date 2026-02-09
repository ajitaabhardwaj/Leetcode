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
        

        for(int j=i; j<candidates.size(); j++)
        {
        currans.push_back(candidates[j]);
        remaining = remaining-candidates[j];
        solve(j, currans, remaining, candidates, target, ans);
        currans.pop_back();
        remaining = remaining+candidates[j];
        }
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