#include <iostream>
#include <string>
using namespace std;
string mergeAlternately(string word1, string word2)
{
    int l1 = word1.length();
    int l2 = word2.length();
    int min_l = 0;
    bool flag = 0;
    if (l1 > l2)
    {
        min_l = l1;
        flag = 1;
    }
    else
    {
        min_l = l2;
    }
    string sum;
    for (int i = 0; i < min_l; i++)
    {
        sum = sum + word1[i] + word2[i];
    }
    if (flag)
    {
        sum = sum + word1.substr(min_l);
    }
    else
    {
        sum = sum + word2.substr(min_l);
    }

    return sum;
}
int main(int argc, char const *argv[])
{
    string s1 = "ab";
    string s2 = "pqrs";
    string s = mergeAlternately(s1, s2);
    cout << s << endl;
    system("pause");
    return 0;
}
