# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if root is None:
            return root
        else:
            return self._deleteNode(root, key)
    
    def getMin(self, root):
        if root is None:
            return None
        else:
            self._getMin(root)
    
    def _getMin(self, root):
        if root.left is None:
            return root.val
        else:
            return self._getMin(root.left)
    
    
    # Returns new root after deletion
    def _deleteNode(self, root, key):
        
        if root is None:
            return root
        
        # Search value lesser, go left
        if key < root.val:
            root.left = self._deleteNode(root.left, key)
        
        # Search value lesser, go right
        elif key > root.val:
            root.right = self._deleteNode(root.right, key)
        
        #Search value matched
        else:
            #Single child or no child
            if (not root.left) or (not root.right):
                temp = root
                if root.left: 
                    root = root.left
                else:
                    root = root.right
                del temp
            else:
                root.val = self._getMin(root.right)
                root.right = self._deleteNode(root.right, root.val)
        return root
