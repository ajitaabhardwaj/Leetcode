class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        for(int i=0; i<s.length(); i++){
            last[s[i]-'a']=i;
        }
        vector<int> ans;
        int prevend = 0;
        int prevstart = 0;
        for(int i=0; i<s.length(); i++){
            int curr = s[i]-'a';
            int currstart = i;
            int currend = last[curr];

            if(currstart<=prevend){
                prevend = max(currend, prevend);
            }
            else{
                ans.push_back(prevend-prevstart+1);
                prevend = currend;
                prevstart = currstart;
            }
        }
        ans.push_back(prevend-prevstart+1);
        return ans;
    }
};