#!/bin/bash
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        unique_num = set()
        max_num = 0
        l = 0
        for r in range(len(s)):
            if s[r] not in unique_num:
                unique_num.add(s[r])
            else:
                max_num = max(max_num, len(unique_num))
                while s[r] in unique_num:
                    unique_num.remove(s[l])
                    l += 1
                unique_num.add(s[r])
        max_num = max(max_num, len(unique_num))
        return max_num

s = "abcabcbb"
print(Solution().lengthOfLongestSubstring(s))