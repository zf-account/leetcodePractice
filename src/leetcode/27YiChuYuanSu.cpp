#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n;right++){
            if(nums[right]!=val){
                nums[left]=nums[right];
                left++;
            }
        }
        return left;
    }
};

int main(){
    vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution s;
    int res = s.removeElement(nums,val);
    cout<<res<<endl;
    return 0;
}