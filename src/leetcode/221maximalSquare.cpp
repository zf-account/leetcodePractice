#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1));
        int max_side = 0;
        for (int i = 1; i < r + 1; ++i){
            for (int j = 1; j < c + 1; ++j){
                if(matrix[i - 1][j - 1] == '1'){  // 注意C++中单字符用' ',字符串用' '
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        return max_side * max_side;
    }
};

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    Solution s;
    cout << s.maximalSquare(matrix) << endl;
    return 0;
}
