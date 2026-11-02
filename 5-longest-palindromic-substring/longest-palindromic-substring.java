class Solution {
    int ans = 1;
    int ansstart = 0;

    void find(String s, int start, int end, int tempans){
        int tempansstart = 0;
        while(start>=0 && end<s.length()){
            if(s.charAt(start) == s.charAt(end)){
                tempansstart = start;
                start--;
                end++;
                tempans+=2;
            }
            else{
                break;
            }
        }
        if(ans < tempans){
            ans = tempans;
            ansstart = tempansstart;
        }
    }
    public String longestPalindrome(String s) {
        String ansString;
        for(int i=0; i<s.length(); i++) {
            int mid = i;
            int start = i-1;
            int end = i+1;
            find(s, i-1, i+1, 1);
            find(s, i, i+1, 0);
        }
        return s.substring(ansstart, ans+ansstart);
    }
}