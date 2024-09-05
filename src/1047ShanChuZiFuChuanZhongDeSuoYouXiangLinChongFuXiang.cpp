#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
/* ----------------------------------------------------- 直接使用栈 ----------------------------------------------------- */
// class Solution
// {
// public:
//     string removeDuplicates(string s)
//     {
//         stack<char> st;
//         for (char ch : s)
//         {
//             if (!st.empty() && st.top() == ch)
//             {
//                 st.pop();
//             }
//             else
//             {
//                 st.push(ch);
//             }
//         }
//         string re;
//         while (!st.empty())
//         {
//             re.push_back(st.top());
//             st.pop();
//         }
//         reverse(re.begin(), re.end());
//         return re;
//     }
// };
/* ---------------------------------------------------------- 用字符串模拟栈的行为 -------------------------------------------------------- */
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string re;
        for(char ch: s){
            if(re.empty() || re.back() != ch)
            re.push_back(ch);
            else
                re.pop_back();
        }
        return re;
    }
};

int main(int argc, char *argv[])
{
    string s = "abbaca";
    cout<<Solution().removeDuplicates(s)<<endl;
    return 0;
}
