class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
       
        int i=0;

        if(s.length() != t.length())
            return false;

        while(i<s.length() && i<t.length())
        {
            if(s[i] != t[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
};