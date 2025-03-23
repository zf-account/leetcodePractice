#include <iostream>
#include <string>
#include <vector>
using namespace std;
// /*思路：
// 维护一个可移动窗口，如果在某位置能够种花，其前后位置都为0
// */
// class Solution
// {
// public:
//     bool canPlaceFlowers(vector<int> &flowerbed, int n)
//     {
//         flowerbed.insert(flowerbed.begin(), 0);
//         flowerbed.push_back(0);
//         for (int i = 1; i + 1 < flowerbed.size(); i++)
//         {
//             if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
//             {
//                 flowerbed[i] = 1; // 种花！
//                 n--;
//             }
//         }
//         return n <= 0;
//     }
// };

/*
思路2:贪心
能种花的条件：
    1. 当前位置为0
    2. 左边是边界或者0
    3. 右边是边界或者0
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        for (int i = 0; i < length; i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == length - 1 || flowerbed[i + 1] == 0)) {
                n--;
                flowerbed[i] = 1;
            }
            if (n <= 0) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> flowerbed{0, 0, 1, 0, 0};
    int n = 2;
    Solution su;
    bool re = su.canPlaceFlowers(flowerbed, n);
    cout << re << endl;
    return 0;
}
