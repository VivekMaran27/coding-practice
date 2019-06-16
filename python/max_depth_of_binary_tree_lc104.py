# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import sys
INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize -1

class Solution:
    
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        else:
            curr_depth = 1
            return self._maxDepth(root, curr_depth)
            
    def _maxDepth(self, root, curr_depth):
        if root.left is None and  root.right is None:
            return curr_depth
        else:
            left_depth = self._maxDepth(root.left, curr_depth+1) if root.left else INT_MIN
            right_depth = self._maxDepth(root.right, curr_depth+1) if root.right else INT_MIN
            return max(left_depth, right_depth)
