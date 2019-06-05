import sys

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        result = []
        
        #Sort the list
        intervals.sort()
        index = 0
        print(intervals)
        
        while index < len(intervals):

            #Assume current interval no merge
            start = intervals[index][0]
            end = intervals[index][1]

            # Compare the consecutive indexes, starting next one
            index += 1
                              
            #Accumulate points to merge and update end
            while index < len(intervals) and intervals[index][0] <= end:
                if intervals[index][1] > end:
                    end = intervals[index][1]
                index += 1
            
            result.append((start,end))
        return result
