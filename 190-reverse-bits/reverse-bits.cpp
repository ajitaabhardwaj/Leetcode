class Solution {
public:
    int reverseBits(int n) 
    {
        string bin = "";
        int a = 0;
        while(n!=0)
        {
            char r = '0' + (n%2);
            bin.push_back(r);
            n = n/2;
            a++;
        }
        while(a<32)
        {
            bin.push_back('0');
            a++;
        }
        int i=0;
        int ans = 0;

        while(bin != "")
        {
            int rem = bin[bin.length()-1] - '0';
            ans = ans + (rem * pow(2,i));
            bin.pop_back();
            i++;
        }
        return ans;
    }
};