class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans(n);

        for(int i=0; i<n; i++)
        {
            ans[i] = vector<int>(i+1, -1);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(j==i || j==0)
                {
                    ans[i][j] = 1;
                }
                else
                {
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        return ans;
    }
};