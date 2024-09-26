#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> result; // 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    int pointNum = 0;
    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isValid(const string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }
        if (s[start] == '0' && start != end) //注意这里比较的是字符'0'而不是0
        {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }
            num = num * 10 + (s[i] - '0'); //注意这种求和方式
            if (num > 255)
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if (pointNum == 3) //决定了树的深度
        {
            if (isValid(s, startIndex, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isValid(s, startIndex, i))
            {
                s.insert(s.begin() + i + 1, '.'); //注意插入位置
                pointNum++;
                backtracking(s, i + 2, pointNum); //注意为什么是i+2
                s.erase(s.begin() + i + 1);
                pointNum--;
            }
            else
            {
                break;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        result.clear();
        if (s.size() < 4 || s.size() > 12)
            return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    string s = "1010235234";
    Solution solution;
    vector<string> result = solution.restoreIpAddresses(s);
    for (auto &i : result)
    {
        cout << i << endl;
    }
    return 0;
}
