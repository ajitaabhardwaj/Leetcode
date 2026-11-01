class Solution {
    public int[] numberOfPairs(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            if(mp.containsKey(nums[i])){
                mp.put(nums[i], mp.get(nums[i])+1);
            }
            else{
                mp.put(nums[i], 1);
            }
        }
        int[] ans = new int[2];
        for(Integer val: mp.values()){
            System.out.println(val);
            ans[0] = ans[0] + (val/2);
            ans[1] = ans[1] + (val%2);
        }
        return ans;
    }
}