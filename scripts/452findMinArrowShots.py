from typing import List
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[0])
        prev_end = points[0][1]
        ans = 1
        for i in range(1, len(points)):
            if points[i][0] <= prev_end:
                prev_end = min(points[i][1], prev_end)
            else:
                ans += 1
                prev_end = points[i][1]
        return ans

points = [[1,2],[2,3],[3,4],[4,5]]
print(f"result: {Solution().findMinArrowShots(points)}")