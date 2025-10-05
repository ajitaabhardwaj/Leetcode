class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int lastnum = nums[0];
        int count =1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] == lastnum) count++;
            else count--;

            if(count == 0)  {
                lastnum = nums[i];
                count=1;
            }
        }
        return lastnum;
    }
};