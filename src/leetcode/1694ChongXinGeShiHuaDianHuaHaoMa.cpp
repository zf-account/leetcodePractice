#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reformatNumber(string number)
    {
        string digits;
        for (char ch : number)
        {
            if (isdigit(ch))
            {
                digits.push_back(ch);
            }
        }
        int n = digits.size();
        string re;
        int point = 0;
        while (n)
        {
            if (n > 4)
            {
                re += digits.substr(point, 3) + "-";
                point += 3;
                n -= 3;
            }
            else
            {
                if (n == 4)
                {
                    re += digits.substr(point, 2) + "-" + digits.substr(point + 2, 2);
                }
                else
                {
                    re += digits.substr(point, n);
                }
                break;
            }
        }
        return re;
    }
};
int main(int argc, char *argv[])
{
    string s = "123-3553 5435346-25235 456345";
    cout << Solution().reformatNumber(s) << endl;
    return 0;
}
