#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;

public:
    void backTracking(vector<int> &candidates, int target, int startIndex)
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
            path.push_back(candidates[i]);
            sum += candidates[i];
            backTracking(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backTracking(candidates, target, 0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> re = s.combinationSum(candidates, target);
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
