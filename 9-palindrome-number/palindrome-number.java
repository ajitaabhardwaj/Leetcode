class Solution {
    public boolean isPalindrome(int x) {
        int num=0;
        int div = x;
        while (div != 0){
            int rem = div%10;
            div = div/10;
            num = (num*10)+rem;
        }
        System.out.println(num);
        if (num == x && x>=0){
            return true;
        }
        else{
            return false;
        }
    }
}