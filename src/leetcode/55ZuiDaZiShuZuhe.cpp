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
        for (int slow = 0; slow < nums.size(); slow++)
        {
            int curSum = 0;
            for (int fast = slow; fast < nums.size(); fast++)
            {
                curSum += nums[fast];
                if (curSum > sum)
                {
                    sum = curSum;
                }
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
