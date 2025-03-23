#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; --i)
        {
            if(++digits[i] < 10)
                return digits;
            else
                digits[i] %= 10;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main(int argc, char *argv[])
{
    vector<int> nums={9,9,9};
    Solution su;
    vector<int> res = su.plusOne(nums);
    for (int i = 0; i < res.size();i++)
        cout << res[i] << endl;
    return 0;
}
