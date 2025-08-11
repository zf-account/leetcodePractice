#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        vector<string> result;
        while(right < n)
        {
            if(right + 1 < n && nums[right + 1] == nums[right] + 1){
                right++;
            }
            else
            {
                if(left == right){
                    result.push_back(to_string(nums[left]));
                }else{
                    result.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                }
                left = right + 1;
                right++;
            }
        }
        return result;
    }
};

int main()
{
    Solution su;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> re = su.summaryRanges(nums);
    int n = re.size();
    for (int i = 0; i < n; ++i)
    {
        cout << re[i] << endl;
    }
    return 0;
}

