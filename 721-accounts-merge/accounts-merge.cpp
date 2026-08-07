class Solution {
public:
    void unions(int a, int b, vector<int>& parent){
        int rootA = find(a, parent);
        int rootB = find(b, parent);

        parent[rootB] = rootA;
        return;
    }
    int find(int a, vector<int>& parent){
        if(a == parent[a]){
            return a;
        }

        return parent[a] = find(parent[a], parent);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        unordered_map<string, int> id;
        unordered_map<int, string> idtoname;
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string email = accounts[i][j];
                string name = accounts[i][0];
                if(id.find(email) == id.end()){
                    id[email] = i;
                }
                idtoname[i] = name;
                
            }
        }

        vector<int>parent(accounts.size() - 1+1);
        for(int i=0; i<accounts.size(); i++)
            parent[i] = i;

        for(int i=0; i<accounts.size(); i++){
            for(int j=2; j<accounts[i].size(); j++){
                if(j<=1)
                    break;
                unions(id[accounts[i][1]], id[accounts[i][j]], parent);
            }
        }

       unordered_map<int, vector<string>> ans2;
        for(auto& [key, value]: id){
            //key - email
            //value - id
            //parent[value] - tells which id the email finally belongs to
            //idtoname[parent[value]] -> string name

            ans2[find(value, parent)].push_back(key); 
        }
        int x=0;
        for(auto& [key, value]: ans2){
            vector<string> temp;
            temp.push_back(idtoname[key]);
            for(int i=0; i<value.size(); i++){
                temp.push_back(value[i]);
            }
            sort(temp.begin()+1, temp.end());
            ans.push_back(temp);
        }
        return ans;
    
    }
};