class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n= nums.size();

        vector<int> sums (n, 0);
        int ans = 0;

        if(nums.size() == 1)
        {
            return nums[0];
        }
        sums[n-1] = nums[n-1];
        sums[n-2] = nums[n-2];

        ans = max (sums[n-1], sums[n-2]);

        for(int i=n-3; i>=0; i--)
        {
            if(i+3 < n)
            {
                sums[i] = max ((sums[i+2] + nums[i]), (sums[i+3] + nums[i]));
            }
            else{
                sums[i] = nums[i] + sums[i+2];
            }
            ans = max(ans, sums[i]);
        }
        return ans;
    }
};