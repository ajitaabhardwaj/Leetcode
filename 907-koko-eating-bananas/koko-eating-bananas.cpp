class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        long long int n = piles.size();
        long long int start = 1;
        long long int end = *max_element(piles.begin(), piles.end());
        
        while(start<=end){
            long long int mid = start + (end - start) / 2;
            long long int hrs = 0;
            for(int i=0; i<n; i++){
                hrs += piles[i]/mid;
                if (piles[i]%mid >0 ) hrs++;
            }
            if(hrs<=h){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};