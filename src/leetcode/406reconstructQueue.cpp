#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
             });
        vector<vector<int>> ans;
        for (const vector<int> &person : people)
        {
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};
    vector<vector<int>> results = Solution().reconstructQueue(people);
    for (const vector<int> &result : results)
    {
        cout << result[0] << " "<< result[1] << endl;
    }
    return 0;
}
