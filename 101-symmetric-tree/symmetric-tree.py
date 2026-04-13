# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        q = deque()
        q.append(root)
        
        while q:
            arr = []
            for a in range(len(q)):
                qele = q.popleft()
                if qele == "null":
                    arr.append("null")
                    continue
                arr.append(qele.val)
                q.append(qele.left if qele.left else "null")
                q.append(qele.right if qele.right else "null")

            print(arr)
            print('\n')

            if arr != arr[::-1]:
                return False
               

        return True
            
        

            


            
        