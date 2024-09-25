// 注意子集问题与组合问题、分割问题的区别
    // 1. 子集问题：收集所有节点的结果
    // 2. 组合问题：收集叶子节点的结果
    // 3. 分割问题：收集所有叶子节点的结果
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTracking(vector<int> &num, int startIndex)
    {
        result.push_back(path);
        if (startIndex >= num.size())
        {
            return;
        }
        for (int i = startIndex; i < num.size(); i++)
        {
            path.push_back(num[i]);
            backTracking(num, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetd(vector<int> &num)
    {
        backTracking(num, 0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> num = {1, 2, 3, 4, 5};
    vector<vector<int>> re = Solution().subsetd(num);
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
