/*
思路：如果可以被整除，可以理解为S为T的n次重复，此时，str1+str2=str3+str1
相等的情况下，求最长的可以分别被str1和str2除尽的字符串，只需要求两个字符串长度的最大公因数即可，可以使用C++自带库函数gcd或使用辗转相除法
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
/*-------------------------方法一：使用gcd------------------------------------------*/
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string str_1 = str1 + str2;
        string str_2 = str2 + str1;
        if (str_1 != str_2)
            return "";
        else
            return str1.substr(0, std::gcd((int)str1.length(), (int)str2.length()));
    }
};

/*------------------------------------方法二：使用辗转相除法----------------------------*/
class Solution2
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2)
    {
        string str_1 = str1 + str2;
        string str_2 = str2 + str1;
        if (str_1 != str_2)
            return "";
        else
            return str1.substr(0, this->gcd((int)str1.length(), (int)str2.length()));
    }
};

int main()
{
    Solution2 ceshi;
    string str1 = "ABAB";
    string str2 = "AB";
    string sum;
    sum = ceshi.gcdOfStrings(str1, str2);
    cout << sum << endl;
    return 0;
}