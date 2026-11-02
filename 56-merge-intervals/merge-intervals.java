class Solution {
    public int[][] merge(int[][] interval) {
        List<int []> ans = new ArrayList<>();
        Arrays.sort(interval, (a,b) -> Integer.compare(a[0], b[0]));
        ans.add(interval[0]);
        for(int i=1; i<interval.length; i++){
            int s;
            int e;
            if(ans.isEmpty()){
                s = interval[0][0];
                e = interval[0][1];
            }
            else{
                s = ans.get(ans.size()-1)[0];
                e = ans.get(ans.size()-1)[1];
            }
            int s2 = interval[i][0];
            int e2 = interval[i][1];
        
            if( (s2>=s && s2<=e) || (e>=s2 && s<=e2)){
                    if(!ans.isEmpty()) ans.remove(ans.size()-1);
                    int[] it = new int []{Math.min(s, s2), Math.max(e, e2)};
                    ans.add(it);
                }
            else{
                    ans.add(interval[i]);
                }
        }

        return ans.toArray(new int[ans.size()][2]);
    }
}