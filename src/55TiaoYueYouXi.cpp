#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cover = 0;
        for (int i = 0; i <= cover; ++i)
        {
            cover = max(cover, i + nums[i]);
            if (cover >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 3, 1, 1, 0, 4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}
