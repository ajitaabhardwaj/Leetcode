class Solution:
    def stringIndices(self, wordsContainer, wordsQuery):
        trie = {}
        
        def better(i, j):
            if j == -1:
                return True
            if len(wordsContainer[i]) < len(wordsContainer[j]):
                return True
            if len(wordsContainer[i]) == len(wordsContainer[j]) and i < j:
                return True
            return False
        
        # root answer handles empty suffix case
        trie["idx"] = -1
        
        for i, word in enumerate(wordsContainer):
            node = trie
            
            if better(i, node["idx"]):
                node["idx"] = i
            
            for ch in reversed(word):
                if ch not in node:
                    node[ch] = {"idx": -1}
                node = node[ch]
                
                if better(i, node["idx"]):
                    node["idx"] = i
        
        ans = []
        
        for q in wordsQuery:
            node = trie
            
            for ch in reversed(q):
                if ch not in node:
                    break
                node = node[ch]
            
            ans.append(node["idx"])
        
        return ans