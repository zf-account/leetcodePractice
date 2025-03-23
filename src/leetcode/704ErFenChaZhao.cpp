// 这道题需要特别注意的是边界条件的处理
#include <iostream>
#include <vector>

using namespace std;
/* --------------------------------------------------- 左闭右闭写法 --------------------------------------------- */
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         while (left <= right) { //注意为什么是小于等于
//             int mid = (left + right) / 2;
//             if (nums[mid] > target) {
//                 right = mid - 1; //注意为什么是mid-1
//             } else if (nums[mid] < target) {
//                 left = mid + 1; //注意为什么是mid+1
//             } else
//                 return mid;
//         }
//         return -1;
//     }
// };
/* --------------------------------------------------- 左闭右开写法 --------------------------------------------- */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) { //注意为什么是小于
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid; //注意为什么是mid
            } else if (nums[mid] < target) {
                left = mid + 1; //注意为什么是mid+1
            } else
                return mid;
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
