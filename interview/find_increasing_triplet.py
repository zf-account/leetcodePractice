## 题目描述
# 寻找递增的三元组
# 输入：长度为N的整型无序数组A
# 输出：如果A中包含递增的三元组，则返回1，否则返回0，递增的三元组定义为A_i<=A_j<=A_k，注意i,j,k可以不连续
def find_increasing_triplet(nums):
    first = float('inf')    # float('inf')代表正无穷大
    second = float('inf')

    for num in nums:
        if num > second:
            return 1
        elif num <= first:
            first = num
        else:
            second = num
    return 0

if __name__ == "__main__":
    test_cases = [
        [1,2,3,4,5],
        [5,4,3,2,1],
        [5,1,5,5,2,5,4],
        [2,4,-2,-3],
        [1,3,0,5],
        [1,1,1,1,1],
        [1,2,1,2,1,2]
    ]
    for nums in test_cases:
        print(find_increasing_triplet(nums))