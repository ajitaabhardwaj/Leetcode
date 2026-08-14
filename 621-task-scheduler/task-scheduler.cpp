class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> q;
        vector<int> freq(26,0);
        for(int i=0; i<tasks.size(); i++){
            freq[tasks[i]-'A']++;
        }

        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;
            pair<int, char> p {freq[i], char(i+'A')};
            q.push(p);
        }

        int count= 0;
    
        while(!q.empty()){
            vector<pair<int, char>>used;
            int run = 0;
            for(int i=0; i<=n && !q.empty(); i++){    
                auto [f, l] = q.top();
                q.pop();
                run++;
                count++;
                if(--f>0) {                   
                    used.push_back({f, l});  
                }
            }
     
            for(auto u:used){
                q.push(u);
            }
            if(!q.empty() && run<n+1){
                count+= n+1-run;
            }
        }
        return count;
    }
};