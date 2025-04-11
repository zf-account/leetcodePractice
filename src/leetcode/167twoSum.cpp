#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ans;
        while (right > left) {
            if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
    vector<int> numbers = {2, 7, 11, 13};
    int target = 9;
    vector<int> results = Solution().twoSum(numbers, target);
    for(int result:results){
        cout << result << endl;
    }
    return 0;
}
