class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int prod = 1;
            int num = n;
            while(num>0){
                int digit = num%10;
                num = num/10;
                prod *= digit;
            }

            if(prod%t == 0){
                return n;
            }
            else{
                n++;
            }
        }
        
    }
};