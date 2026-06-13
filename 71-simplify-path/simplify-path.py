class Solution:
    def simplifyPath(self, path: str) -> str:
        dir = path.split("/")
        ans = ""
        st = []
        for char in dir:
            if char == "..":
                if st:
                    st.pop()
            elif char == "." or char == "":
                continue
            else:
                st.append(char)
           
         
        for a in st:
            if a == "" or a == ".":
                continue
            ans = ans + "/" + a 

        if ans == "":
            return "/"
        return ans
           

            
