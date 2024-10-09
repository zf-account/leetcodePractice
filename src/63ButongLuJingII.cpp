#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - 1 >= 0 && j - 1 >= 0 && obstacleGrid[i - 1][j] == 0 &&
                    obstacleGrid[i][j - 1] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else if (i - 1 >= 0 && j - 1 >= 0 && obstacleGrid[i - 1][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (i - 1 >= 0 && j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                if (i - 1 >= 0 && j - 1 < 0 && obstacleGrid[i - 1][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j - 1 >= 0 && i - 1 < 0 && obstacleGrid[i][j - 1] == 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int res = Solution().uniquePathsWithObstacles(grid);
    cout << res << endl;
    return 0;
}
