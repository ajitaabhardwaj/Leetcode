class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        int n=nums.length;
        int k=0;
        HashSet<Integer> s = new HashSet<>();
        while(k<n){
            s.add(nums[k]);
            int target = 0-nums[k];
            int start = k+1;
            int end = n-1;
            
            while(start<end){
                if (nums[start] + nums[end] == target){
                    ans.add(List.of(nums[k], nums[start], nums[end]));
                    while(start < end && nums[start]==nums[start+1]) start++;
                    while(start < end && nums[end]==nums[end-1]) end--;
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end] > target){
                    end--;
                }
                else{
                    start++;
                }
                
            }
            while(k+1<n && nums[k+1] == nums[k]){
                k++;
            }
            k++;
        }
        return ans;
    }
}