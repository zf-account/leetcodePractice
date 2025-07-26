"""题目描述
用python写一个快排并给出时间复杂度
时间复杂度: O(nlogn)
空间复杂度: O(logn)
"""

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    base = arr[len(arr) // 2]
    left = [x for x in arr if x < base]
    middle = [x for x in arr if x == base]
    right = [x for x in arr if x > base]
    return quick_sort(left) + middle + quick_sort(right)

if __name__ == "__main__":
    test_cases = [
        [4, 2, 1, 3],
        [1, 1, 1, 1],
        [5, 4, 3, 2, 1],
        [1, 2, 3, 4, 5],
        [3, 1, 4, 1, 5, 9, 2, 6],
        []
    ]
    
    for i, test_case in enumerate(test_cases):
        print(f"测试用例 {i+1}: {test_case}")
        sorted_array = quick_sort(test_case)
        print(f"排序结果: {sorted_array}")