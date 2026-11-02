class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();

        for(int i=0; i<nums.length; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0)+1);
        }

        for(Map.Entry<Integer, Integer> e: mp.entrySet()){
            int key = e.getKey();
            int value = e.getValue();

            if (value>1){
                return true;
            }
        }
        return false;
    }
}