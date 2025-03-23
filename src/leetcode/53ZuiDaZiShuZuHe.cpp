#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = std::numeric_limits<int>::min();
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curSum += nums[i];
            if (curSum > sum)
            {
                sum = curSum;
            }
            if (curSum < 0)
            {
                curSum = 0;
            }
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;
}