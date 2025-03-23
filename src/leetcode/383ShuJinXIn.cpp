// 383. 赎金信
// 注意表示字符数组的这种方式，还有先加后减的思想
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;
        vector<int> cnt(26);
        for (const char& ele1 : magazine) {
            cnt[ele1 - 'a']++;
        }
        for (const char& ele2 : ransomNote) {
            cnt[ele2 - 'a']--;
            if (cnt[ele2 - 'a'] < 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s = "ajsghisg";
    string t = "ajsghsgi";
    cout << Solution().canConstruct(s, t) << endl;
    return 0;
}
