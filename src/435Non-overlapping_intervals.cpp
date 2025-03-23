/*
    1. 注意在sort函数中使用lambda表达式进行特定方式的排序
*/
#include <iostream>

using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int remove = 0, prev_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prev_end)
            {
                remove++;
            }
            else
            {
                prev_end = intervals[i][1];
            }
        }
        return remove;
    }
};

int main()
{
    vector<vector<int>>intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution su;
    cout << "remove nums: " << su.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
