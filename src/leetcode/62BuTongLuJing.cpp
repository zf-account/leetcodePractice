#include <iostream>
#include <vector>

using namespace std;
/* -------------------------- 初始化第一行和第一列 ------------------------- */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

/* --------------------------- 初始化左上角值为1 ------------------------- */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         dp[0][0] = 1;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i - 1 >= 0 && j - 1 >= 0) {
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//                 } else if (i - 1 >= 0 && j - 1 < 0) {
//                     dp[i][j] = dp[i - 1][j];
//                 } else if (j - 1 >= 0 && i - 1 < 0) {
//                     dp[i][j] = dp[i][j - 1];
//                 }
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

int main(int argc, char const *argv[])
{
    int m = 3, n = 7;
    cout << Solution().uniquePaths(m, n) << endl;
    return 0;
}
