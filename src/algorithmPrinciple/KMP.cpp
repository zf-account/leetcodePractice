#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    void getNext (int* next, const string& s){
        next[0] = 0;
        int j = 0; //j指向前缀末尾位置，j同时代表了包含i的之前的子串的最长相等前后缀的长度
        for(int i = 1;i < s.size(); i++){ //i指向后缀末尾位置
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
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    string s = "abab";
    int next[s.size()];
    
    return 0;
}
