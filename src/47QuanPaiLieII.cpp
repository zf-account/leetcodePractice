#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(vector<int> &nums, vector<bool> used)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == true ||
                (i > 0 && nums[i] == nums[i - 1]) && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backTracking(nums, used);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 1};
    vector<vector<int>> result = Solution().permuteUnique(nums);
    for (auto &i : result)
    {
        for (auto &j : i)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
