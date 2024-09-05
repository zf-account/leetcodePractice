#include <iostream>
#include <vector>

using namespace std;
/* ------------------------------------------------------ 四指针解法 -------------------------------------------- */
// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> result(n, vector<int> (n));
//         int left = 0, right = n - 1, top = 0, bottom = n - 1, j = 1;
//         while (left <= right && top <= bottom) {
//             if (right < left)
//                 break;
//             for (int i = left; i <= right; i++) {
//                 result[top][i] = j++;
//             }
//             top++;
//             if (top > bottom)
//                 break;
//             for (int i = top; i <= bottom; i++) {
//                 result[i][right] = j++;
//             }
//             right--;
//             if (right < left)
//                 break;
//             for (int i = right; i >= left; i--) {
//                 result[bottom][i] = j++;
//             }
//             bottom--;
//             if (bottom < top)
//                 break;
//             for (int i = bottom; i >= top; i--) {
//                 result[i][left] = j++;
//             }
//             left++;
//         }
//         return result;
//     }
// };
/* ------------------------------------------------------ 左闭右开边界条件解法 -------------------------------------------- */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int startX = 0, startY = 0, offset = 1, loop = n / 2;
        int count = 1, i, j, mid = n / 2;
        while (loop--) {//loop为循环次数：如果n为偶数，则循环次数为n/2，如果n为奇数，则循环次数为n/2+1，最中间的位置最后赋值
            i = startX, j = startY;
            for (j; j < n - offset; j++) {
                result[i][j] = count++;
            }
            for (i; i < n - offset; i++) {
                result[i][j] = count++;
            }
            for (j; j > startY; j--) {
                result[i][j] = count++;
            }
            for (i; i > startX; i--) {
                result[i][j] = count++;
            }
            startX++;
            startY++;
            offset += 1;
        }
        if (n % 2)
            result[mid][mid] = count;
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> result = Solution().generateMatrix(3);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

