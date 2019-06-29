class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        
        length = len(nums)
        result = [1]*length
        productSoFar = 1
        
        #Forward pass
        for i in range (1, length):
            productSoFar = productSoFar * nums[i-1]
            result[i] = result[i]* productSoFar
            
        productSoFar = 1
        
        #Reverse pass
        for i in range(length-2, -1, -1):
            productSoFar = productSoFar * nums[i+1]
            result[i] = result[i]*productSoFar
            
        return result
