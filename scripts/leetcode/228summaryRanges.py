from typing import List
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        left, right = 0, 0
        n = len(nums)
        result = []
        while right < n:
            if right + 1 < n and nums[right + 1] - nums[right] ==1:
                right += 1
            else:
                if left != right:
                    result.append(f"{nums[left]}->{nums[right]}")
                else:
                    result.append(f"{nums[left]}")
                left = right + 1
                right += 1
        return result

list1 = [0, 1, 2, 4, 5, 7]
print(f"{Solution().summaryRanges(list1)}")