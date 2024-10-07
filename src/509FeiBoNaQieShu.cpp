#include <iostream>
/* ------------------------------ 递归：时间复杂度高 ------------------------------------ */
// class Solution
// {
// public:
//     int fib(int n)
//     {
//         if (n <= 1)
//             return n;
//         return fib(n - 1) + fib(n - 2);
//     }
// };

/* ------------------------------ 动态规划 ------------------------------------ */
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; ++i)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;
    std::cout << Solution().fib(n) << std::endl;
    return 0;
}
