from typing import List
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        pt1 = m - 1
        pt2 = n - 1
        tail = m + n - 1
        while tail > -1:
            if pt1 == -1:
                cur = nums2[pt2]
                pt2 -= 1
            elif pt2 == -1:
                cur = nums1[pt1]
                pt1 -= 1
            elif nums1[pt1] > nums2[pt2]:
                cur = nums1[pt1]
                pt1 -= 1
            else:
                cur = nums2[pt2]
                pt2 -= 1
            nums1[tail] = cur
            tail -= 1
nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3
Solution().merge(nums1, m, nums2, n)
print(f"results: {nums1}")