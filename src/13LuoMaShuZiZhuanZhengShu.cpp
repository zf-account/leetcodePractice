#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        int b = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            int c = romanMap[s[i]];
            if (c < b)
            {
                sum -= c;
            }
            else
            {
                sum += c;
            }
            b = c;
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    string s = "IVII";
    Solution su;
    int sum = su.romanToInt(s);
    cout << sum << endl;
    return 0;
}
