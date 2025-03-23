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
    void backTracking(int k, int n, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == n)
            {
                result.push_back(path);
            }
            return;
        }
        for (int i = startIndex; i <= 9; i++)
        {
            path.push_back(i);
            sum += i;
            backTracking(k, n, i + 1);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTracking(k, n, 1);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int k = 3;
    int n = 9;
    vector<vector<int>> re = s.combinationSum3(k, n);
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
