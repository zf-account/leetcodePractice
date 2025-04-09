/*
注意什么时候修改nums[i - 1]，什么时候修改nums[i]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                count++;
            }
        }
        return count <= 1;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums= {3, 4, 2, 3};
    cout << Solution().checkPossibility(nums) << endl;
    return 0;
}
