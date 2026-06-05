class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        if len(s)<=1:
            return False
        for brac in s:
            
            if brac == '(' or brac == '[' or brac == '{':
                st.append(brac)
            else:
                if len(st) == 0:
                    return False
                b = st.pop()
                if brac == ')' and b == '(':
                    continue
                elif brac == ']' and b == '[':
                    continue
                elif brac == '}' and  b == '{':
                    continue
                else:
                    return False
        if len(st) == 0:
            return True
        return False
        