#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 1e9, maxprofit = 0;
        for (int price : prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
int main(int argc, char *argv[])
{
    int arr[] = {7, 1, 5, 3, 9, 4};
    std::vector<int> prices(arr, arr + sizeof(arr) / sizeof(arr[0]));
    Solution su;
    int max = su.maxProfit(prices);
    cout << max << endl;
    return 0;
}
