// 这道题得注意数字和字符之间的转换关系，如何从字符转数字进行计算，再数字转字符输出结果，还要注意reverse函数的用法
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = max(num1.size(), num2.size());
        int carry = 0;
        vector<int> result;
        string ans;
        for (int i = 0; i < n; i++)
        {
            carry += i < num1.size() ? num1[i] - '0' : 0;
            carry += i < num2.size() ? num2[i] - '0' : 0;
            result.push_back((carry % 10 >= 0) ? carry % 10 : carry);
            carry = carry / 10;
        }
        if (carry)
        {
            result.push_back(1);
        }
        for (int i : result)
        {
            ans.push_back(i + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string num1 = "1";
    string num2 = "9";
    Solution su;
    cout << su.addStrings(num1, num2) << endl;
    return 0;
}
