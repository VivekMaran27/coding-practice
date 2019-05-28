import heapq
from math import sqrt
from functools import cmp_to_key

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        
        distanceList = []
        originDistanceDict = {}
        pointTuple = ()
        result=[]
        
        #Custom comparator which sorts the points by euclidiean distance
        def func (p1, p2):
            p1_dist =  sqrt((p1[0]*p1[0]) + (p1[1]*p1[1]))
            p2_dist =  sqrt((p2[0]*p2[0]) + (p2[1]*p2[1]))
            if (p1_dist < p2_dist):
                return -1
            elif (p1_dist > p2_dist):
                return 1
            else:
                return 0
            
        # Sort the points using custom comparator
        points.sort(key=cmp_to_key(func))
        
        # Append first K points from sorted list
        for i in range(0,K):
            result.append(points[i])
        return result
