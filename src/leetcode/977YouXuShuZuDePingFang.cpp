// 最朴素的做法是暴力法，时间复杂度O(n^2)，空间复杂度O(1)，先求平方再排序，更简单的方法是使用双指针
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int k = result.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[k--] = nums[i] * nums[i];
                i++;
            } else {
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {-4,-1,0,3,10};
    for(int i: Solution().sortedSquares(nums)){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
