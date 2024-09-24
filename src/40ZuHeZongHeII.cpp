#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;
    void backTracking(vector<int> &candidates, int target, int startIndex, vector<bool> used)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && (sum + candidates[i]) <= target; i++)
        {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backTracking(candidates, target, i + 1, used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        backTracking(candidates, target, 0, used);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> re = s.combinationSum2(candidates, target);
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
