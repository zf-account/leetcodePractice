#include <iostream>
#include <string>

using namespace std;
// 方法一：求和
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        int as=0,at=0;
        for(char ch:s){
            as+=ch;
        }
        for(char ch:t){
            at+=ch;
        }
        return at-as;
    }
};
// 方法二：位运算
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        int ret=0;
        for(char ch:s){
            ret^=ch;
        }
        for(char ch:t){
            ret^=ch;
        }
        return ret;
    }
};
int main(int argc, char *argv[])
{
    
    return 0;
}
