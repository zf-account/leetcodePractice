#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> candy(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++)
        {
            // 右边比左边大
            if (ratings[i] < ratings[i + 1])
            {
                candy[i + 1] = candy[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--)
        {
            // 左边比右边大
            if (ratings[i - 1] > ratings[i])
            {
                candy[i - 1] = max(candy[i] + 1, candy[i - 1]);
            }
        }
        int result = 0;
        for (int i = 0; i < candy.size(); i++)
        {
            result += candy[i];
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ratings = {1, 2, 2};
    Solution s;
    cout << s.candy(ratings) << endl;
    return 0;
}
