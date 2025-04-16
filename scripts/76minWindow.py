class Solution:
    def minWindow(self, s: str, t: str) -> str:
        freq = dict()
        for c in t:
            freq[c] = freq.get(c, 0) + 1
        min_l, min_length = None, None
        count = 0
        l = 0
        for r in range(len(s)):
            if s[r] not in freq:
                continue
            freq[s[r]] -= 1
            if freq[s[r]] >= 0:
                count += 1
            while count == len(t):
                if min_length == None or r - l + 1 < min_length:
                    min_l = l
                    min_length = r - l + 1
                # if s[l] in freq and freq[s[l]] + 1 > 0:
                #     count -= 1
                if s[l] in freq:
                    freq[s[l]] += 1
                    if freq[s[l]] > 0:
                        count -= 1
                l += 1
        return "" if min_length == None else s[min_l: min_l + min_length]
s = "ADOBECODEBANC"
t = "ABC"
print(f"results: {Solution().minWindow(s, t)}")