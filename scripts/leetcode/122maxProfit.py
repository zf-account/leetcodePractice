from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        chajia = list()
        ans = 0
        for i in range(1, len(prices)):
            chajia.append(prices[i] - prices[i - 1])
        for i, ch in enumerate(chajia):
            if ch > 0:
                ans += ch
        return ans

prices = [7,1,5,3,6,4]
print(f"result: {Solution().maxProfit(prices)}")