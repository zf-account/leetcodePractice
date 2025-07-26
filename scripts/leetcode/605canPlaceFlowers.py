from typing import List
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed.insert(0, 0)
        flowerbed.append(0) # 注意这里不能使用flowerbed.insert(-1, 0)
        for i in range(1, len(flowerbed) - 1):
            if flowerbed[i] == 0 and flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
                n -= 1
                flowerbed[i] = 1
            if n <= 0:
                return True
        return False

flowerbed = [1,0,0,0,0,1]
print(f"bool : {Solution().canPlaceFlowers(flowerbed, 2)}")