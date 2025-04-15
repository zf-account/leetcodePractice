#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// -----------------------解法一：直接合并后排序---------------------
class Solution1 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m);
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
    }
};


// -----------------------解法二：逆向双指针-----------------------
class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int cur;
        int tail = m + n - 1;
        while (tail>-1) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
