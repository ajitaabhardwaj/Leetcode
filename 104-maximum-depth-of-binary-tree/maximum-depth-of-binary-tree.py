# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        global maxlen
        maxlen = 0
        def dfs(node, length):
            global maxlen
            if not node:
                return
            print(f'node: {node.val}, length: {length}')
            length+=1
            maxlen = max(length, maxlen)
            dfs(node.left, length)
            dfs(node.right, length)

        dfs(root, 0)
        return maxlen
