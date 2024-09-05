#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX; //常数定义需要<cstdint>头文件
        int i = 0;  // 滑动窗口的左边界
        int sum = 0, subLength = 0;
        for (int j = 0; j < nums.size(); j++) {// j 为滑动窗口的右边界
            sum += nums[j];
            while (sum >= target) { //这是为什么使用while不使用if
                subLength = j - i + 1;
                result = subLength < result ? subLength : result;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;//对于输出结果的处理
    }
};
int main(int argc, char const *argv[])
{
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    cout<<Solution().minSubArrayLen(target, nums)<<endl;
    return 0;
}
