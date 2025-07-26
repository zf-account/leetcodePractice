## 题目描述
# 寻找最长公共子序列并返回
# 给定两个字符串t1和t2，返回这两个字符串的最长公共子序列的长度，并且返回最长公共子序列
# 如果不存在，返回0和空字符串

def longest_common_subsequence(t1, t2):
    m, n = len(t1), len(t2)

    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if t1[i - 1] == t2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    lcs = []
    i, j = m, n
    while i > 0 and j > 0:
        if t1[i - 1] == t2[j - 1]:
            lcs.append(t1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    lcs.reverse()
    return dp[m][n], "".join(lcs)

t1 = "ABCBDAB"
t2 = "BDCAB"
length, lcs = longest_common_subsequence(t1, t2)
print(f"length: {length}, lcs: {lcs}")
