#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*思路：
先找出没有增加额外糖果之前，糖果最大值
之后遍历每一个值，增加额外的糖果之后，与最大值比较，大于等于最大值则设置为true，否则设为false*/
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> result(candies.size(), false);
        int max_candies = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > max_candies)
            {
                max_candies = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); i++)
        {
            int extraSum = 0;
            extraSum = candies[i] + extraCandies;
            if (extraSum >= max_candies)
            {
                result[i] = true;
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> candies(5);
    candies[0] = 2;
    candies[1] = 3;
    candies[2] = 5;
    candies[3] = 1;
    candies[4] = 3;
    int extraCandies = 3;
    Solution result;
    vector<bool> re(5);
    re = result.kidsWithCandies(candies, extraCandies);
    for (int i = 0; i < 5; i++)
    {
        cout << re[i] << endl;
    }
    return 0;
}
