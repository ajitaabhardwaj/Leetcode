# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.dicts = {}
        self.count=0
        self.dicts[0] = 1

        
        def dfs(node, runningsum):
            if not node:
                return

            runningsum +=  node.val

            if runningsum-targetSum in self.dicts:
                self.count += self.dicts[runningsum-targetSum]

            if runningsum in self.dicts:
                self.dicts[runningsum] += 1
            else:
                self.dicts[runningsum]=1
            
            dfs(node.left, runningsum)
            dfs(node.right, runningsum)

            
            self.dicts[runningsum]-=1
            if self.dicts[runningsum] == 0:
                del self.dicts[runningsum]

        dfs(root, 0)
        return self.count