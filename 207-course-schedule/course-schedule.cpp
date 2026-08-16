class Solution {
public:
/*
//[a, b] means a -> b

0->1
1->2
0->2
(how many subject to complete this subject?) like for compling 2 0 dependencies
0: 2
1: 1
2: 0

courses start from 0-n or random?
*/

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n, 0);
        queue<int> q;
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }

        for(int i=0; i<n ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<adj[curr].size(); i++){
                int nbr = adj[curr][i];
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(indegree[i]!=0){
                return false;
            }
        }
        return true;

    }
};