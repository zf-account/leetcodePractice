#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int i = 1, sum = 0;
        for (char ch : s) {
            sum += (int(ch) - (71 + (int(ch) - 97) * 2)) * i;
            ++i;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abc";
    cout << Solution().reverseDegree(s) << endl;
    return 0;
}
