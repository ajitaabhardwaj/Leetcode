class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prevend = intervals[0][1];
        int count = 0;

        for(int i=1; i<intervals.size(); i++){
            int currstart = intervals[i][0];
            int currend = intervals[i][1];
            if(currstart < prevend){
                count++;
                prevend = min(prevend, currend);
            }
            else{
                prevend = currend;
            }

        }
        return count;
    }
};