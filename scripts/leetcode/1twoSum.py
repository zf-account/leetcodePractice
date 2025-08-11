from typing import List
class Solution:
    def twoSum(self, nums:List[int], target:int) -> List[int]:
        hashtable = dict()
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return []

if __name__=="__main__":
    nums = [3, 2, 4]
    target = 6
    result = Solution().twoSum(nums, target)
    print(f"result:{result}")