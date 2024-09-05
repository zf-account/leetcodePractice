#include <iostream>
#include <string>

using namespace std;
/* C++中string有实现API：tolower() 使用示例：ch=tolower(ch);，下面实现该API
大写字母A - Z的ASCII码范围是[65, 90]
小写字母a - z的ASCII码范围是[97, 122]
因此，大写字母的ASCII码值加上32即可得到小写字母的ASCII码值，反之亦然。
[65, 90]的二进制表示为[01000001, 01011010],32对应的二进制为00100000，而对于[01000001, 01011010]内的所有数，
表示32的那个二进制位都是0，因此可以对大写字母的ASCII码与32进行按位或操作，替代与32的加法操作，即可得到结果
*/
class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch: s) {
            if (ch >= 65 && ch <= 90) {
                ch |= 32;
            }
        }
        return s;
    }
};
int main(int argc, char  *argv[])
{
    
    return 0;
}
