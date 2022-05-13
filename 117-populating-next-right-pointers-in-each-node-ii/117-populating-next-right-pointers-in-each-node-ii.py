"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        deque = collections.deque()
        
        if root:
            deque.append(root);
            
        while deque:
            size = len(deque)
            for i in range(size):
                l = deque.popleft();
                if i != size-1: # last node in each level has no next
                    l.next = deque[0];
                    
                if l.left:
                    deque.append(l.left);
                if l.right:
                    deque.append(l.right);
                    
        return root;