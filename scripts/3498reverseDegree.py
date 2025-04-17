class Solution:
    def reverseDegree(self, s: str) -> int:
        sum = 0
        for i, ch in enumerate(s):
            sum += (ord(ch) - (71 + 2 * (ord(ch) - ord("a")))) * (i + 1)
        return sum

s = "abc"
print(f"results: {Solution().reverseDegree(s)}")