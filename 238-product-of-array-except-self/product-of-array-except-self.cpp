class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> fr(nums.size(), 1);
        vector<int> bck(nums.size(), 1);
        int numofzero = 0;
        fr[0] = 1;
        bck[nums.size()-1] = 1;
        int prod = 1;
        int prod2 = 1;

        for(int i=0 ; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                numofzero++;
                fr[i] = 1;
                continue;
            }
            fr[i] = prod;
            prod = prod * nums[i];  
        }

        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] == 0)
            {
                bck[i] = nums[i];
                continue;
            }
            bck[i] = prod2;
            prod2 = prod2 * nums[i];  
        }

        if(numofzero > 1)
        {
            vector<int> ans(nums.size(), 0);
            return ans;
        }
        else if(numofzero == 0){
            for(int i=0; i<nums.size(); i++)
            {
                nums[i] = fr[i] * bck[i];
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