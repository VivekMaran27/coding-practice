"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    
    def __init__(self):
        self.node_to_index_orig_dict = {}
        self.index_to_node_copy_dict = {}
        
    def copyRandomList(self, head: 'Node') -> 'Node':
        
        node = head
        copy_head = None
        copy_tail = None
        node_count = 0
        
        #Copy the list and create two dicts
        # Map node to index for original dict
        # Map index to node for copy dict
        while node is not None:
            copy_node=Node(node.val, None, None)
            if copy_head is None:
                copy_head = copy_node
                copy_tail = copy_node
            else:
                old_copy_tail = copy_tail
                copy_tail = copy_node
                old_copy_tail.next = copy_tail
            
            self.node_to_index_orig_dict[node] = node_count
            self.index_to_node_copy_dict[node_count] = copy_node
            node = node.next
            node_count = node_count + 1
        
        node = head
        copy_node = copy_head
        while node is not None and copy_node is not None:
            #print (f"Orig node {node.val}, Copy node {node.val}")
            if node.random is None:
                copy_node.random = None
            else:
                random_idx = self.node_to_index_orig_dict[node.random]
                copy_node.random = self.index_to_node_copy_dict[random_idx]
            node = node.next
            copy_node = copy_node.next

        return copy_head
