/* 优雅的滑动滑动窗口，
    有几个需要注意的点：
    1.insert()函数的返回值是std::pair，第二个值是bool，表示插入是否成功；
    2.比较大小时，哈希集合的size()函数返回值是size_type类型，需要转换为int类型，否则无法使用max()函数，这里可以使用if判断替代max */
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0, i = 0;
        unordered_set<char> subStr;
        for (int j = 0; j < s.size(); j++) {
            while (!(subStr.insert(s[j]).second)) {
                subStr.erase(s[i]);
                i++;
            }
            maxL = max(maxL, (int)subStr.size());
        }
        return maxL;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
