class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i=0;
        int j=0;
        int count=0;
        while(i< nums.size() && j<nums.size())
        {
            if(nums[i]==val)
            {
                if(nums[j]!=val)
                {
                    std::swap(nums[i], nums[j]);
                    i++;
                }
                j++;
            }
            else{
                i++;
                j++;
            }
        }

        for(auto n : nums)
        {
            if(n != val) count++;
        }
        return count;

    }
};