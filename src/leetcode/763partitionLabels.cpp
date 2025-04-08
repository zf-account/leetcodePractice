#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        // 记录每个字符最后出现的位置
        vector<int> last(26, 0);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            // 更新当前分区的最远边界
            right = max(right, last[s[i] - 'a']);
            if (i == right) {
                // 到达当前分区的最远边界，添加分区长度
                ans.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return ans;
    }
};


int main(int argc, char *argv[])
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = Solution().partitionLabels(s);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
