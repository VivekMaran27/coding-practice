import sys

max = sys.maxsize
min = -sys.maxsize -1

class Solution:

    def longestPalindrome(self, s: str) -> str:
        
        start = 0 
        end = 0
        
        #For each character
        for i in range(len(s)):
        
            lOdd, rOdd = self.longestPalindForChar(s, i, i)
            lEven, rEven = self.longestPalindForChar(s, i, i+1)
           
            #Decide whether to take odd or even left/right
            if  (rEven - lEven) > (rOdd - lOdd):
                l,r = lEven,rEven
            else:
                l,r = lOdd,rOdd
                
            #print(f"l:{l}, r:{r}, i:{i}")
            
            #Update start,end
            if(r - l) > (end - start):
                start,end = l,r
        
        return s[start:end+1]
                
            
    def longestPalindForChar(self, s, left, right):
        
        while (left >= 0) and (right < len(s)) and s[left] == s[right]:
            left -=1
            right +=1
            
        return left+1,right-1
