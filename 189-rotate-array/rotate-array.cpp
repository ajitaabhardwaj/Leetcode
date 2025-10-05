class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if(k>nums.size()) k=k%nums.size();
        for(int i=0; i<nums.size()/2; i++){
            int dummy = nums[i];
            nums[i] = nums[nums.size()-1-i];
            nums[nums.size()-1-i] = dummy;
        }
        int halfsize = k-1;
        for(int i=0; i<k/2; i++){
            int dummy = nums[i];
            nums[i] = nums[halfsize-i];
            nums[halfsize-i] = dummy;
        }
        for(int i=0; i<(nums.size()-k)/2; i++){
            int dummy = nums[i+k];
            nums[i+k] = nums[nums.size()-1-i];
            nums[nums.size()-1-i] = dummy;
        }
    }
};