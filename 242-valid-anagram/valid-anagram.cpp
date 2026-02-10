class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        int i=0;
        while(i<s.length())
        {

            if(mp1.find(s[i]) == mp1.end())
            {
                mp1[s[i]] = 1;
            }
            else{
                mp1[s[i]]++;
            }
            if(mp2.find(t[i]) == mp2.end())
            {
                mp2[t[i]] = 1;
            }
            else{
                mp2[t[i]]++;
            }
            i++;
        }

        if(mp1 == mp2)
        {
            return true;
        }
        return false;
    }
};