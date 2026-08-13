class Solution {
public:
    bool canJump(vector<int>& nums) {
       int steps = 0;
       for(int i=nums.size()-2; i>=0; i--){
            steps++;
            if(steps<=nums[i]){
                steps = 0;
            }
       }     
       return steps==0;
    }
};