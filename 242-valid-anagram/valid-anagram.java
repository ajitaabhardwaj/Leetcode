class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> mp = new HashMap<>();
        for(int i=0; i<s.length(); i++){
            mp.put(s.charAt(i), mp.getOrDefault(s.charAt(i), 0)+1);
        }
        Map<Character, Integer> mp2 = new HashMap<>();
        for(int i=0; i<t.length(); i++){
            mp2.put(t.charAt(i), mp2.getOrDefault(t.charAt(i), 0)+1);
        }
        if (mp.equals(mp2)) return true;
        return false;
    }
}