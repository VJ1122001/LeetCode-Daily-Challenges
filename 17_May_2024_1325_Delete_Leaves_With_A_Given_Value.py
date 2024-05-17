# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    #TC: O(N) SC: O(1)
    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        def dfs(r):
            if r is None:
                return None
            
            right= dfs(r.right)
            left= dfs(r.left)
            
            r.left = left
            r.right= right
            
            if r.val == target and r.left is None and r.right is None:
                return None
            return r
        
        return dfs(root)
