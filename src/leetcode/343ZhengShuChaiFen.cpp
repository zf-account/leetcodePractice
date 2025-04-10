#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int integerbreak(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.integerbreak(10) << endl;
    return 0;
}
