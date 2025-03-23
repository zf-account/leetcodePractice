#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> path;
    vector<vector<string>> result;

public:
    bool isPalindrome(string s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin] != s[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
    void backTracking(string &s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++)
        {
            if (isPalindrome(s, startIndex, i))
            {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            }
            else
            {
                continue;
            }
            backTracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        result.clear();
        path.clear();
        backTracking(s, 0);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    string s = "asadafasasasasas";
    vector<vector<string>> re = Solution().partition(s);
    for (auto &i : re)
    {
        for (auto &j : i)
            cout << j << endl;
    }
    return 0;
}
