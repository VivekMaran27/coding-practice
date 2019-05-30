class Solution:
    def trap(self, height: List[int]) -> int:
   
        maxSeenSoFar = 0
        maxSeenRight = [None]*len(height)
        maxSeenLeft = 0
        numRainBlocks = 0
        
        #Track the max value in right
        for i in range(len(height)-1,-1,-1):
            if(height[i] > maxSeenSoFar):
                maxSeenSoFar = height[i]
            maxSeenRight[i] = maxSeenSoFar
    
        """
        1. Track maxSeenLeft
        2. Check if the current index has one tower left and one tower right
        3. If so, the number of water blocks in that tower is:
            min(maxSeenLeft,maxSeenRight) - currentTowerHeight
        """
        maxSeenSoFar = 0
        for i in range(0,len(height)):
            if(height[i] > maxSeenLeft):
                maxSeenLeft = height[i]
            #print(f"maxSeenRight[{i}]={maxSeenRight[i]}, maxSeenLeft={maxSeenLeft}, height[{i}]={height[i]}")
            numRainBlocks += max((min(maxSeenRight[i],maxSeenLeft)-height[i]),0)
        
        return numRainBlocks
