class Solution:
    def reverseWords(self, s: str) -> str:
        i = 0
        words = s.split(" ")
        j = len(words)-1

        while i<j:
            words[i], words[j] = words[j], words[i]
            i+=1
            j-=1

        ans = ""
        print(words)

        for i, word in enumerate(words):
            if word is "":
                continue
            ans = ans + word + " "

        return ans.strip()



