#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// 自己写的
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length())
//             return false;
//         for (int i = 0; i < s.length(); ++i) {
//             for (int j = 0; j < t.length(); ++j) {
//                 if (s[i] == t[j]) {
//                     t.erase(j, 1);
//                     break;
//                 }
//             }
//         }
//         if (t.length() == 0)
//             return true;
//         else
//             return false;
//     }
// };


/* ------------------------------ 哈希表 ------------------------------ */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int hash[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (hash[i] != 0)
                return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) {
//             return false;
//         }
//         vector<int> table(26, 0);
//         for (auto& ch: s) {
//             table[ch - 'a']++;
//         }
//         for (auto& ch: t) {
//             table[ch - 'a']--;
//             if (table[ch - 'a'] < 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

int main(int argc, char const *argv[])
{
    string s = "aacc";
    string t = "ccac";
    Solution su;
    cout << su.isAnagram(s, t) << endl;
    return 0;
}
