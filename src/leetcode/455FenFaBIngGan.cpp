#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (i < g.size() && g[i] <= s[j])
            {
                i++;
            }
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> g = {1, 2, 9, 0, 2, 4};
    vector<int> s = {1, 2, 3, 3};
    cout << Solution().findContentChildren(g, s) << endl;
    return 0;
}
