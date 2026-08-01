class Solution {
public:
    void dfs(int n, vector<bool>& visited, vector<vector<int>>& isConnected)
    {
        for(int i=0; i<visited.size(); i++)
        {
            if(n==i)
            {
                continue;
            }
            if(isConnected[n][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                dfs(i, visited, isConnected);
            }
        }
        cout<<endl;
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int ans=0;
        int n = isConnected.size();

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++)
        {
            if( visited[i] == false)
            {
                visited[i] == true;
                dfs(i, visited, isConnected);
                ans++;
            }
        }
        return ans;
        
    }
};