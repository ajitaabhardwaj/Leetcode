class Solution {
public:

    int find(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        return parent[node] = find(parent[node], parent);
    }

    void unions(int a, int b, vector<int>& parent){
        int rootA = find(a, parent);
        int rootB = find(b, parent);
            parent[rootB] = rootA;
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() ==1)
            return 1;

        vector<int> parent(isConnected.size(), 0);
        for(int i=0; i<isConnected.size(); i++)
            parent[i] = i;

        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(i==j)
                    continue;
                if(isConnected[i][j] == 1){
                    unions(i, j, parent);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<parent.size(); i++){
            if (parent[i] == i)
                ans++;
        }
        return ans;
    }
};