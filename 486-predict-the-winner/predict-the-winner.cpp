class Solution {
public:

    int dp(int i, int j, vector<int>& nums)
    {
        if(i==j)
        {
            return nums[i];
        }
        else{
            return max(
                nums[i] - dp(i+1, j, nums),
                nums[j] - dp(i, j-1, nums)
            );
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        if(dp(0,nums.size()-1, nums) <0){
            return false;        
        }
        else{
            return true;
        }
    }
};