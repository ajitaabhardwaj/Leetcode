# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        node = {}
        s = set()
        for element in descriptions:
            node[element[0]] = TreeNode(element[0])
            node[element[1]] = TreeNode(element[1])
            s.add(element[1])

        root = TreeNode()
        for element in descriptions:
            if element[0] not in s:
                root = element[0]
        
        for parent, child, left in descriptions:
            if left == 1:
                node[parent].left = node[child]
            elif left == 0:
                node[parent].right = node[child]

        return node[root]

        


                
        