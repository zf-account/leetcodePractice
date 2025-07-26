from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        ans = list()
        while left < right:
            if numbers[left] + numbers[right] > target:
                right -= 1
            elif numbers[left] + numbers[right] < target:
                left += 1
            else:
                ans.append(left + 1)
                ans.append(right + 1)
                break
        return ans

numbers = [2,7,11,15]
target = 9
print(f"result: {Solution().twoSum(numbers, target)}")