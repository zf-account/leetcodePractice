from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        r = len(matrix)
        c = len(matrix[0])
        max_side = 0
        dp = [[0] * (c + 1) for _ in range(r + 1)]
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                    max_side = max(max_side, dp[i][j])
        
        return max_side ** 2


matrix = [['1','0','1','0','0'],['1','0','1','1','1'],['1','1','1','1','1'],['1','0','0','1','0']]
su = Solution()
print(su.maximalSquare(matrix))
