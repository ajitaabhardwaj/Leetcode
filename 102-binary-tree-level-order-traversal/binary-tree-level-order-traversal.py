# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        ans = []
        q.append(root)
        while q:
            arr = []
            for _ in range(len(q)):
                qele = q.popleft()
                if qele == None:
                    continue
                if qele == "null":
                    continue
                else:
                    q.append(qele.left if qele.left else "null")
                    q.append(qele.right if qele.right else "null")
                    arr.append(qele.val)
            if arr:
                ans.append(arr)

        return ans
        