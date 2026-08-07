class Solution {
public:

    void unions(int a, int b, vector<int>& parent){
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        
        parent[rootB] = rootA;
    }

    int find(int node, vector<int>& parent){
        if(node == parent[node])
            return node;

        return parent[node] = find(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> parent(edges.size()+1);
        for(int i=0; i<edges.size(); i++)
            parent[i] = i;

        for(int i=0; i<edges.size(); i++){
            if( find(edges[i][0], parent) == find(edges[i][1], parent) )
                return {edges[i][0], edges[i][1]};
    
            unions(edges[i][0], edges[i][1], parent);
        }
        return ans;
    }
};