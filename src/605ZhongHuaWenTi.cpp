#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*思路：
维护一个可移动窗口，如果在某位置能够种花，其前后位置都为0
*/
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i + 1 < flowerbed.size(); i++)
        {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1; // 种花！
                n--;
            }
        }
        return n <= 0;
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
