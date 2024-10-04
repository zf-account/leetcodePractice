#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(int row, int col, char ch, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch)
            {
                return false;
            }
        }
        for (int j = 0; j < 9; j++)
        {
            if (board[row][j] == ch)
            {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int row = startRow; row < startRow + 3; row++)
        {
            for (int col = startCol; col < startCol + 3; col++)
            {
                if (board[row][col] == ch)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool backTracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (board[i][j] != '.')
                    continue;
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isValid(i, j, ch, board))
                    {
                        board[i][j] = ch;
                        if (backTracking(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board) { backTracking(board); }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution().solveSudoku(board);
    for (auto row : board)
    {
        for (auto ch : row)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}
