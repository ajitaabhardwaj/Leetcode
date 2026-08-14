class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<pair<int,int>> pq;
 
        for(int i=0; i<people.size(); i++){
            pq.push({people[i][0], -people[i][1]});
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [h, k] = pq.top();
            pq.pop();
            int index = -k;
           
            ans.insert(ans.begin()+index, {h, index});
        }
        return ans;
    }
};