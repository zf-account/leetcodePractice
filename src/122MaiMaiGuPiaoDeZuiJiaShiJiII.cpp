// 贪心：算出每一步的利润，只要利润为正，就加入总和，否则丢弃
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxprofit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            profit += max(prices[i] - prices[i - 1], 0);
            // profit += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
        }
        return profit;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxprofit(prices) << endl;
    return 0;
}
