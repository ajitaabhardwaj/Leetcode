class Solution {
public:
    void solve(int i, vector<int>& currans, int currtotal, vector<int>& candidates, int target,vector<vector<int>>& ans)
    {
        if(currtotal == target)
        {
            int flag1 = 0;
            for(int a=0; a<ans.size(); a++)
            {
                int count = 0;
                if(currans.size() == ans[a].size())
                {
                    for(int b=0; b<currans.size();b++)
                    {
                        if(currans[b] == ans[a][b])
                        {
                            count++;
                        }
                    }
                    if(count == currans.size())
                        {
                            flag1 =1;
                        }
                }

            }
            if(flag1 == 0)
                {
                    ans.push_back(currans);
                }
            return;
        }
        if(i==candidates.size() || currtotal > target)
        {
            return;
        }
        std::cout<<i<<" "<<currtotal<<endl;


        solve(i+1, currans, currtotal, candidates, target, ans);

        currans.push_back(candidates[i]);
        currtotal = currtotal+candidates[i];
        solve(i+1, currans, currtotal, candidates, target, ans);
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