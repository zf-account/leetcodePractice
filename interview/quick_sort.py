"""题目描述
用python写一个快排并给出时间复杂度
"""

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    base = arr[len(arr) // 2]
    left = [x for x in arr if x < base]
    middle = [x for x in arr if x == base]
    right = [x for x in arr if x > base]
    return quick_sort(left) + middle + quick_sort(right)

arr = [3, 6, 8, 10, 1, 2, 1]
print(quick_sort(arr))