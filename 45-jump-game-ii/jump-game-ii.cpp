class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count=0;
        while(r<nums.size()-1){
            int far = 0;
            for(int i=l; i<=r; i++){
                far = max(far, i+nums[i]);
            }
            count++;
            l+=1;
            r=far;
            if(far>=nums.size()-1) break;

        }
        return count;
    }
};