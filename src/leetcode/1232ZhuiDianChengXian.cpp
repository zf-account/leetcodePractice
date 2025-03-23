/* 注意点：1.避免除法运算，一方面考虑除0问题，一方面考虑除法开销比乘法大很多*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        /*
         *   一般式：Ax+By+C=0（AB≠0）
         *   两点式：(y-y1)/(x-x1)=(y-y2)/(x-x2) 　（直线过定点(x1,y1),(x2,y2)）
         */

        // 这里取定点为coordinates[0],和coordinates[n-1]
        // 为避免除法运算，这里用“两内项的积等于两外项的积”计算
        int n = coordinates.size();
        for (int i = 1; i < coordinates.size() - 1; ++i) {
            if ((coordinates[i][0] - coordinates[0][0]) * /* (x-x1)*(y-y2) */
                    (coordinates[i][1] - coordinates[n - 1][1]) !=
                (coordinates[i][1] - coordinates[0][1]) * /* (y-y1)*(x-x2) */
                    (coordinates[i][0] - coordinates[n - 1][0])

            )
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> coordinates = {{-4, -3}, {1, 0}, {3, -1}, {0, -1}, {-5, 2}};
    Solution sol;
    cout << sol.checkStraightLine(coordinates) << endl;
    return 0;
}
