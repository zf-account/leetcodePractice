#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && k > 0; i++)
        {
            if (nums[i] < 0)
            {
                int temp = -nums[i];
                nums[i] = temp;
                k--;
            }
            else
            {
                break;
            }
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return k % 2 == 0 ? sum : sum - 2 * nums[0];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 2, 3};
    cout << Solution().largestSumAfterKNegations(nums, 1) << endl;
    return 0;
}
