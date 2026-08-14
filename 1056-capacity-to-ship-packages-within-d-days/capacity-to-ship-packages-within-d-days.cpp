class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int end = 0;
        int start = 0;
        for(int i=0; i<weights.size(); i++){
            end+=weights[i];
            start = max(start, weights[i]);
        }


        while(start<=end){
            int mid = start + (end - start) / 2;

            int count = 0;
            int day = 1;
            for(int i=0; i<weights.size(); i++){
                count+=weights[i];
                if(count>mid){
                    count = weights[i];
                    day++;
                }
            }
            if(day>days){
                start = mid+1;
            }
            if(day<=days){
                end = mid-1;
            }
        }
        return start;
    }
};