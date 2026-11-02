class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> s = new HashSet<>();
        for(int i=0; i<nums.length; i++){
            if(!s.add(nums[i])) return true;
        }
        return false;
    }
}