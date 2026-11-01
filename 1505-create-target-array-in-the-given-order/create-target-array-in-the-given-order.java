class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int n = index.length;
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<index.length; i++)
        {
            int ind = index[i];
            int val = nums[i];

            list.add(ind, val);
        }
        int[] target = new int[n];
        for(int i=0; i<n; i++)
        {
            target[i] = list.get(i);
        }
        return target;
    }
}