// 这道题最重要的是学会去重
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* ------------------------------------------------------- 相向双指针 ------------------------------------------------------- */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int right = n - 1;
            for (int left = i + 1; left < n; ++left) {
                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    continue;
                }
                while (left < right && nums[left] + nums[right] > target) {
                    right--;
                }
                if (left == right) {
                    break;
                }
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                }
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution su;
    vector<vector<int>> result = su.threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
           cout << result[i][j] << " ";
        }
    }
    return 0;
}
