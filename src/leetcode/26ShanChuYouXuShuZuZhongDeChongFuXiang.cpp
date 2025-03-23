#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*--------------------------------方法一：直接调用库函数unique排除重复元素----------------------------*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
};
/*--------------------------------方法二：使用双指针-----------------------------------------------*/
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{0,0,0,0,1,1,1,1,1,1,2,2,2,2,2,5,5,5,6,6,6,6,7,7,7,8,9};
    Solution2 su;
    int re = su.removeDuplicates(nums);
    cout << re<< endl;
    for (int i = 0; i < re;++i){
        cout << nums[i] << endl;
    }
    return 0;
}
