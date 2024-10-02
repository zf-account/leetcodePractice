#include <iostream>
#include <vector>

using namespace std;
class Solution
{
private:
    vector<vector<string>> result;

public:
    bool isValid(int row, int col, vector<string> &chessboard, int n)
    {
        for (int i = 0; i < n; i++)
        { // 检查列
            if (chessboard[i][col] == 'Q')
            {
                return false;
            }
        }
        // for (int j = 0; j < n; j++){
        //     if(chessboard[row][j] == 'Q'){
        //         return false;
        //     }
        // }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        { // 检查副对角线
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        { // 检查主对角线
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void backTracking(int row, int n, vector<string> &chessboard)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValid(row, col, chessboard, n))
            {
                chessboard[row][col] = 'Q';
                backTracking(row + 1, n, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> chessboard(n, string(n, '.'));
        backTracking(0, n, chessboard);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<string>> result = Solution().solveNQueens(4);
    for (auto &i : result)
    {
        for (auto &j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
