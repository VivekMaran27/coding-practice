class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        
        if not intervals:
            return 0
        
        intervals.sort()
        meeting_ends =[]
        heapq.heapify(meeting_ends)
        heapq.heappush(meeting_ends,(intervals[0][1],intervals[0]))
        
        for i in range (1, len(intervals)):
            curr_interval = intervals[i]
            earliest_end = heapq.heappop(meeting_ends)[1]
            if curr_interval[0] >= earliest_end[1]:
                earliest_end[1] = curr_interval[1]
            else:
                heapq.heappush(meeting_ends, (curr_interval[1],curr_interval))
            heapq.heappush(meeting_ends, (earliest_end[1],earliest_end))
        
        return len(meeting_ends)
