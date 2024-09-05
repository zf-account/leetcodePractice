// 动态规划问题https://www.bilibili.com/video/BV1FJ4m1M7RJ/?spm_id_from=trigger_reload&vd_source=17818489fd2f182f58c3c96182580255
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        word1 = "#" + word1;
        word2 = "#" + word2;
        int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
        return dp[m][n];
    }
};
int main(int argc, char *argv[])
{
    string word1 = "horse", word2 = "ros";
    cout<<Solution().minDistance(word1, word2)<<endl;
    return 0;
}
