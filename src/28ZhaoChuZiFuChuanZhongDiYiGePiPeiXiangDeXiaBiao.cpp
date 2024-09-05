#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); ++i) {
            if (haystack[i] == needle[0]) {
                int j = 1, k = i + 1;
                if (needle.length() == 1) {
                    return i;
                } else {
                    while (j < needle.length()) {
                        if (needle[j] == haystack[k]) {
                            ++j;
                            ++k;
                        } else {
                            break;
                        }
                    }
                    if (j == needle.length())
                        return i;
                }
            }
        }
        return -1;
    }
};
int main(int argc, char *argv[])
{
    string haystack = "sadbutsad", needle = "sad";
    Solution su;
    cout << su.strStr(haystack, needle) << endl;
    return 0;
}
