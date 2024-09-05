#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for (int i : row) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i : col) {
            for (int j = 0; j < m; j++) {
                matrix[j][i] = 0;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    Solution su;
    su.setZeroes(matrix);
    return 0;
}
