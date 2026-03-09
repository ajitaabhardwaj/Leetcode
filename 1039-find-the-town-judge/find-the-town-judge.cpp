class Solution {
public:
    int findJudge(int n, vector<vector<int>>& t) 
    {
        vector<int> trust_count(n+1, 0);
        vector<int> trusted_count(n+1, 0);

        trust_count[0] = -1;
        trusted_count[0] = -1;
        for(int i=0; i<t.size(); i++)
        {
            trust_count[t[i][0]] += 1;
            trusted_count[t[i][1]] += 1;
        }

        for(int i=1; i<=n; i++)
        {
            if(trusted_count[i] == n-1)
            {
                if(trust_count[i] == 0)
                {
                    return i;
                }
            }            
        }
        return -1;
        
    }
};