#include <iostream>
#include <vector>

using namespace std;
/*思路：
题目的难点在于获取一个整数的k置位，即一个整数用二进制表示之后有多少个1，这里使用汉明法，这种方法需要记住
*/
class Solution {
public:
    int Hamming_weight_2(int number) {
        int count = 0;      //声明计数变量
        while (number != 0) //遍历
        {
            number &= number - 1;
            count++;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (Hamming_weight_2(i) == k) {
                sum+=nums[i];
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{5,10,1,5,2};
    int k = 1;
    int re=0;
    Solution su;
    re = su.sumIndicesWithKSetBits(nums,k);
    cout << re << endl;
    return 0;
}