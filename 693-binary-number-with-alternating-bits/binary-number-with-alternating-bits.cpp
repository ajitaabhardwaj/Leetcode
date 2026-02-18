class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int  priv = -1;
        while(n!=0)
        {
            int rem = n%2;
            if(priv == rem)
            {
                return false;
            }
            priv = rem;
            n = n/2;
        }
        return true;
    }
};