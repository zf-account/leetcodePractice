#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    // string addBinary(string a, string b) {
    //     string ans;
    //     // reverse用于反转容器中的顺序，可以用于反转数组、向量（vector）、链表（list）、字符串等容器
    //     // 先将其反转过来从最末位开始相加
    //     reverse(a.begin(), a.end());
    //     reverse(b.begin(), b.end());
    //     // 确定迭代的长度
    //     int n = max(a.size(), b.size()), carry = 0;
    //     // 从最末位开始相加a和b的每一位
    //     for (size_t i = 0; i < n; ++i) {
    //         carry += i < a.size() ? (a.at(i) == '1') : 0;
    //         carry += i < b.size() ? (b.at(i) == '1') : 0;
    //         ans.push_back((carry % 2) ? '1' : '0');//取余
    //         carry /= 2;//取商
    //     }
    //     // 如果carry不为0，说明最高位进位了，需要添加进位字符
    //     if (carry) {
    //         ans.push_back('1');
    //     }
    //     //将答案反转过来
    //     reverse(ans.begin(), ans.end());

    //     return ans;
    // }
    string addBinary(string a, string b) {
        string ans;
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            if (m >= 0 && n >= 0)
                carry = carry + int(a[m]) + int(b[n]);
            else if (m >= 0)
                carry = carry + int(a[m]);
            else
                carry = carry + int(b[n]);
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
            m--;
            n--;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


int main(int argc, char *argv[])
{
    string a = "0", b = "0";
    cout << Solution().addBinary(a, b) << endl;
    return 0;
}
