#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* -----------------------------------------官方题解1：枚举----------------------------------------- */
/*
如果一个长度为n的字符串s可以由它的一个长度为n′的子串s′重复多次构成，那么n一定是n′的倍数；s′一定是s的前缀；
对于任意的i∈[n′,n)，有s[i]=s[i−n′]

也就是说，s中长度为n'的前缀就是s'，并且在这之后的每个位置上的字符s[i]，都需要与它之前的第n'个字符s[i-n']相同。
因此，可以从小到大枚举n'，并对字符串s进行遍历，进行上述的判断。因为子串至少重复一次，因此只需遍历一半的长度
*/
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int n = s.size();
//         for (int i = 1; i * 2 <= n; ++i) {
//             if (n % i == 0) {
//                 bool match = true;
//                 for (int j = i; j < n; ++j) {
//                     if (s[j] != s[j - i]) {
//                         match = false;
//                         break;
//                     }
//                 }
//                 if (match) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
/* ----------------------------------------官方题解2: 字符串匹配------------------------------------- */
/*
如果将两个s连在一起，并移除第一个和最后一个字符，那么得到的字符串一定包含s，即s是它的一个子串
*/
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         return (s + s).find(s, 1) != s.size();
//     }
// };

/* ----------------------------------------官方题解3：KMP算法------------------------------------- */
// class Solution {
// public:
//     bool kmp(const string& query, const string& pattern) {
//         int n = query.size();
//         int m = pattern.size();
//         vector<int> fail(m, -1);
//         for (int i = 1; i < m; ++i) {
//             int j = fail[i - 1];
//             while (j != -1 && pattern[j + 1] != pattern[i]) {
//                 j = fail[j];
//             }
//             if (pattern[j + 1] == pattern[i]) {
//                 fail[i] = j + 1;
//             }
//         }
//         int match = -1;
//         for (int i = 1; i < n - 1; ++i) {
//             while (match != -1 && pattern[match + 1] != query[i]) {
//                 match = fail[match];
//             }
//             if (pattern[match + 1] == query[i]) {
//                 ++match;
//                 if (match == m - 1) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//     bool repeatedSubstringPattern(string s) {
//         return kmp(s + s, s);
//     }
// };
/* -------------------------------------官方题解4：优化的KMP算法------------------------------------- */
// class Solution {
// public:
//     bool kmp(const string& pattern) {
//         int n = pattern.size();
//         vector<int> fail(n, -1);
//         for (int i = 1; i < n; ++i) {
//             int j = fail[i - 1];
//             while (j != -1 && pattern[j + 1] != pattern[i]) {
//                 j = fail[j];
//             }
//             if (pattern[j + 1] == pattern[i]) {
//                 fail[i] = j + 1;
//             }
//         }
//         return fail[n - 1] != -1 && n % (n - fail[n - 1] - 1) == 0;
//     }

//     bool repeatedSubstringPattern(string s) {
//         return kmp(s);
//     }
// };
/* ---------------------------------------------------- 一种KMP解法 --------------------------------------------------- */
class Solution {
public:
    void getNext (int* next, const string& s){ //获取next数组，参考算法原理KMP算法
        next[0] = 0;
        int j = 0;
        for(int i = 1;i < s.size(); i++){
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {//如果next数组的最后一个元素不是0，并且字符串长度除以字符串长度减去next数组最后一个元素的余数等于0，则说明该字符串可以重复
                                                                        //  为什么？因为如果存在最小重复子串，那么在字符串中最长相等前后缀不包含的子串就是最小重复子串
            return true;
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
    string s = "abaababaab";
    Solution su;
    bool res = su.repeatedSubstringPattern(s);
    cout << res << endl;
    return 0;
}
