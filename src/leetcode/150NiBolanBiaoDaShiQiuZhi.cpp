#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 力扣修改了后台测试数据，需要用longlong
        stack<long long> st; //这里注意创建long long或者int型的栈，不要创建char型的栈
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") { //这里需要注意都使用双引号，不要使用单引号，C++中双引号和单引号可以区分字符串和字符，单引号只能表示一个字符，双引号可以表示一个字符串
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoll(tokens[i]));//这里需要注意stoll()，不能用atoi()，atoi()只能转换字符串为int，而stoll()可以转换字符串为long long
            }
        }

        int result = st.top();
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout<<Solution().evalRPN(tokens)<<endl;
    return 0;
}
