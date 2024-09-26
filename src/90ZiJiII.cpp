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
    void backTracking(vector<int> &nums, int startIndex, vector<bool> used)
    {
        result.push_back(path);
        if (startIndex >= nums.size())
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTracking(nums, 0, used);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 4, 5, 6};
    Solution s;
    vector<vector<int>> re = s.subsetsWithDup(nums);
    for (auto &i : re)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
