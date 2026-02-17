class Solution {
public:
    void solve(int currenton, int currh, int currm, int i, vector<int>& time, int turnedOn, vector<string>& ans)
    {
        if(currh>11)
        {
            return;
        }
        if(currm>59)
        {
            return;
        }
        if(currenton == turnedOn)
        {
            int h = 0;
            int m = 0;
            string min = "";
            if(currm<10)
            {
                min = "0"+ to_string(currm);
            }
            else{
                min = to_string(currm);
            }
            string t = to_string(currh) + ":" + min;
            ans.push_back(t);
            return;
        }
        if(i > time.size()-1)
        {
            return;
        }

        //not hours not minutes
        solve(currenton, currh, currm, i+1, time, turnedOn, ans);
        if(i+1 < 5)
        {
            currh+=time[i];
        }
        else{
            currm+=time[i];
        }
        solve(currenton+1, currh, currm, i+1, time, turnedOn, ans);
        return;
    }

    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<int> time = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
        vector<string> ans;
        //vector<int> currtime;
        solve(0, 0, 0, 0, time, turnedOn, ans);
        return ans;
    }
};