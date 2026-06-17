class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int ans = -1;
        int start = 0;
        int end = nums.size()-1;

        while(end>=start)
        {
            if (start >= end){
                if (target <= nums[start]) return start;
                else return start+1;
            }

            int mid = (end+start)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid])
            {
                end = mid-1;
            }
            else{
                start = mid+1;
            }

            if (start >= end){
                if (target <= nums[start]) return start;
                else return start+1;
            }
        }

        return nums.size();

    }
};