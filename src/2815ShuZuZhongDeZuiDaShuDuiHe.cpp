#include <iostream>
#include <vector>
using namespace std;
//思路：暴力解法、哈希表、倒序双指针
class Solution {
public:
    int reMax(int num) {
        int a[5] = {0};
        a[0] = num / 10000;
        a[1] = num % 10000 / 1000;
        a[2] = num % 1000 / 100;
        a[3] = num % 100 / 10;
        a[4] = num % 10;
        int remax = 0;
        for (int i = 0; i < 5; i++) {
            if (a[i] > remax) {
                remax = a[i];
            }
        }
        return remax;
    }
    int maxSum(vector<int>& nums) {
        int sum_max = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (reMax(nums[i]) == reMax(nums[j]) &&
                    nums[i] + nums[j] > sum_max) {
                    sum_max = nums[i] + nums[j];
                }
            }
        }
        if (sum_max > 0)
            return sum_max;
        else
            return -1;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums{51,71,17,24,42};
    int re=0;
    Solution su;
    re = su.maxSum(nums);
    cout << re << endl;
    return 0;
}
