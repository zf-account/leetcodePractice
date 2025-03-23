#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// 哈希表
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size();i++){
            auto iter = map.find(target - nums[i]); //学习这种auto 用法,find函数返回的是迭代器,如果没找到,则返回map.end()
            if(iter!=map.end()){
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i));// 学习这种给map中插入元素的写法
        }
            return {};
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums{3, 3};
    vector<int> re(2);
    int target = 6;
    Solution su;
    re = su.twoSum(nums, target);
    cout << re[0] << ' '<< re[1] << endl;
    return 0;
}
