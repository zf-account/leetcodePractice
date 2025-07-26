#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    vector<int> sortArray(vector<int>&nums){
        if(nums.size() <= 1){
            return nums;
        }
        int base = nums[0];
        vector<int> left, middle, right;
        for (int i = 0; i < int(nums.size()); ++i)
        {
            if(nums[i] < base){
                left.push_back(nums[i]);
            }else if(nums[i] == base){
                middle.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }
        left = sortArray(left);
        right = sortArray(right);
        left.insert(left.end(), middle.begin(), middle.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

int main()
{
    Solution su;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sorted = su.sortArray(nums);
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

