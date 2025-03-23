#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int pos = 0, neg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                while (pos < nums.size() && nums[pos] < 0)
                {
                    pos++;
                }
                result[i] = nums[pos++];
            }
            else
            {
                while (neg < nums.size() && nums[neg] > 0)
                {
                    neg++;
                }
                result[i] = nums[neg++];
            }
        }
        return result;
    }
};

int main()
{
    Solution su;
    vector<int> nums = {3, 1, -2, -4, 5, -6};
    vector<int> result = su.rearrangeArray(nums);
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
}