#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<int> st;
        if (s.length() % 2 != 0)
            return false;
        for (char ch : s)
        {
            if (!st.empty())
            {
                if ((st.top() == '(' && ch == ')') ||
                    (st.top() == '{' && ch == '}') ||
                    (st.top() == '[' && ch == ']'))
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            else
            {
                st.push(ch);
            }
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    string s = "()";
    cout << Solution().isValid(s) << endl;
    return 0;
}
