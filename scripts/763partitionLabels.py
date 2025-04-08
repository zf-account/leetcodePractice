'''
解题思路：贪心
1. 注意为什么使用ord(ch) - ord("a"), 而不能直接使用ch - "a"
'''
from typing import List
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = [0] * 26
        for i, ch in enumerate(s):
            last[ord(ch) - ord("a")] = i
        left = 0
        right = 0
        ans = list()
        for j, ch in enumerate(s):
            right = max(right, last[ord(ch) - ord("a")])
            if j == right:
                ans.append(right - left + 1)
                left = right + 1
        return ans

s = "ababcbacadefegdehijhklij"
print(f"result: {Solution().partitionLabels(s)}")