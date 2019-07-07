import sys

max = sys.maxsize
min = -max-1

class Solution:
    
    def __init__(self):
        self.min_so_far = max
        self.result = set()
        self.result_list =[]
        
    def removeInvalidParentheses(self, s: str) -> List[str]:
        slist=[]
        self._removeInvalidParantheses(s, 0, slist, 0, 0, 0)

        for ele in self.result:
            if len(ele) == len(s)-self.min_so_far:
                self.result_list.append(ele)
        
        return self.result_list
        
    def _removeInvalidParantheses(self, s, index, slist, left_count, right_count, rem_count):
        
        #Base case
        if index >= len(s):
            if left_count is right_count and rem_count <= self.min_so_far:
                self.min_so_far = rem_count
                self.result.add(''.join(slist))
            return
        
        #Check if the character is a non parantheses
        if not (s[index] is '(' or s[index] is ')'):
            slist.append(s[index])
            self._removeInvalidParantheses(s, index+1, slist, left_count, right_count, rem_count)
            slist.pop()
        
        else:
            #Choice-1: Do not include the parantheses
            self._removeInvalidParantheses(s, index+1, slist, left_count, right_count, rem_count+1)
        
            #Choice-2: Conditionally include parantheses
            if (s[index] is ')' and left_count > right_count):
                slist.append(s[index])
                self._removeInvalidParantheses(s, index+1, slist, left_count, right_count+1, rem_count)
                slist.pop()
            elif s[index] is '(':
                slist.append(s[index])
                self._removeInvalidParantheses(s, index+1, slist, left_count+1, right_count, rem_count)
                slist.pop()
            else:
                pass
