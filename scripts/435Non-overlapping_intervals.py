"""
    1. list是python内置的实际列表类型
    2. List是用于类型注解的泛型类型(来自typing模块)
    3. 在python3.9+中, 可以直接使用list进行类型注解(即list[list[int]]), 但为了兼容旧版本, 常使用typing.List
    4. 注意在sort函数中使用lambda表达式实现特定方式的排序
"""
from typing import List
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[1]) # sort中使用lambda实现特定方式的排序
        prev_end = intervals[0][1]
        remove = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < prev_end:
                remove += 1
            else:
                prev_end = intervals[i][1]
        return remove

intervals = [[1,2],[2,3],[3,4],[1,3]]
su = Solution()
print(f"remove_nums: {su.eraseOverlapIntervals(intervals)}")