class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int numofzero = 0;
        int prod = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                numofzero++;
            }
            else{
                prod = prod * nums[i];
            }
        }

        if(numofzero > 1)
        {
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        else if(numofzero == 0){
            for(int i=0; i<nums.size(); i++)
            {
                nums[i] = prod / (nums[i]);
            }
        }
        else{
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] == 0)
                {
                    nums[i] = prod;
                }
                else{
                    nums[i] = 0;
                }
            }
        }
        return nums;
    }
};