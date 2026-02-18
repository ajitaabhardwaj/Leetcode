class Solution {
public:

    int solve(int i,int j, vector<vector<int>>& ans)
    {
        //if(i == 0 || i == 1) return 1;
        if(j==i || j==0) return 1;
        if(ans[i][j] != -1)
        {
            return ans[i][j];
        }
        ans[i][j] = solve(i-1, j-1, ans) + solve(i-1, j, ans);
        return ans[i][j];
    }
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans(n);
        for(int i = 0; i<n; i++)
            ans[i] = vector<int>(i+1, -1);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                ans[i][j] = solve(i, j, ans);;
            }
        }
        
        return ans;
    }
};