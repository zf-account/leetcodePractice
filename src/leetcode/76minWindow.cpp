#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<bool> valid(128, false);
        vector<int> freq(128, 0);
        for (int i = 0; i < t.length(); ++i) {
            valid[t[i]] = true;
            ++freq[t[i]];
        }

        int min_l = -1, min_length = -1, count = 0;
        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (!valid[s[r]]) {
                continue;
            }
            if (--freq[s[r]] >= 0) {
                ++count;
            }
            while (count == t.length()) {
                if (min_length == -1 || r - l + 1 < min_length) {
                    min_l = l;
                    min_length = r - l + 1;
                }
                if (valid[s[l]] && ++freq[s[l]] > 0) {
                    --count;
                }
                ++l;
            }
        }
        return min_length == -1 ? "" : s.substr(min_l, min_length);
    }
};

int main(int argc, char *argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}
