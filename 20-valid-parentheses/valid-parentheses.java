class Solution {
    public boolean isValid(String s) {
        Deque<Character> st = new ArrayDeque<>();
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(c=='{' || c=='(' || c=='['){
                st.push(c);
            }
            else{
                if(st.isEmpty()) return false;
                if(c=='}' && st.peek()=='{'){
                    st.pop();
                }
                else if(c==')' && st.peek()=='('){
                    st.pop();
                }
                else if(c==']' && st.peek()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(!st.isEmpty()) return false;
        
        return true;
    }
}