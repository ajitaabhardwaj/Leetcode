class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int prevend = points[0][1];
        int count = 1;
        for(int i=1; i<points.size(); i++){
            int currstart = points[i][0];
            int currend = points[i][1];
            if(currstart <= prevend){
                prevend = min(prevend, currend);
            }
            else{
                prevend = currend;
                count++;
            }
        }
        return count;
    }
};