#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());// 学习这种用vector元素初始化set的方式
        for (int num : nums2)
        {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end())//find函数查找num值,如果找到,则返回一个指向该元素的迭代器,否则返回一个指向num_set结束位置的迭代器,即num_set.end()
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());// 学习这种用set元素初始化vector的方式
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> re = Solution().intersection(nums1, nums2);
    for (const int &ele : re)
    {
        cout << ele << endl;
        cout << " ";
    }
    return 0;
}
