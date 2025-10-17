class Solution {
public:

    int climbStairs(int n) {
        int a=1;
        int b=2;

        if(n<=2)
        {
            return n;
        }
        int i=3;
        long long c;

        while(i<=n){
            c = a + b;
            a = b;
            b = c;
            i++;
        }
        return b;
    }
};