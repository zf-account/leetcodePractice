from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        result = []
        nums.sort()
        for i in range(n):
            if nums[i] > 0:
                return result
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            right = n - 1
            for left in range(i + 1, n):
                if left > i + 1 and nums[left] == nums[left - 1]:
                    continue
                while left < right and nums[left] + nums[right] > target:
                    right -= 1
                if left == right:
                    break
                if nums[left] + nums[right] == target:
                    result.append([nums[i], nums[left], nums[right]])
        return result



s = Solution()
nums = [-1,0,1,2,-1,-4]
print(s.threeSum(nums))