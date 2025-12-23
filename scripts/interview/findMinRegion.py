"""
题目描述：
有n个货位，有m类商品，每个货位上的商品类别用一个列表items表示，b表示每一类商品至少需要出现多少次，
求满足b条件的items的最小区间，区间长度定义为r - l + 1
"""
n = 10
m = 4
items = [3, 1, 2, 1, 3, 4, 2, 1, 3, 2]
b = [2, 1, 0, 1]

# 只关心 1~m 的计数
item_map = {i: 0 for i in range(1, m+1)}

l = 0
cnt = float('inf')

for r in range(n):
    if items[r] in item_map:
        item_map[items[r]] += 1

    # 检查当前窗口是否满足条件
    def check():
        for i, need in enumerate(b):
            if item_map[i+1] < need:
                return False
        return True

    # 满足条件时，收缩左边界
    while check() and l <= r:
        cnt = min(cnt, r - l + 1)
        if items[l] in item_map:
            item_map[items[l]] -= 1
        l += 1

print(cnt if cnt != float('inf') else -1)