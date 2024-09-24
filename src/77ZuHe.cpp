#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backtracking(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return result;
    }
};

/* // 测试类继承自 ::testing::Test
class CombinationTest : public ::testing::Test {
protected:
    Solution solution;

    void SetUp() override {
        // 在每个测试用例之前执行的初始化代码
    }

    void TearDown() override {
        // 在每个测试用例之后执行的清理代码
    }
};

// 测试用例
TEST_F(CombinationTest, TestCombineWithN4K2) {
    std::vector<std::vector<int>> expected{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    std::vector<std::vector<int>> actual = Solution().combine(4, 2);

    // 对结果进行排序以便比较
    std::sort(actual.begin(), actual.end());
    for (auto &vec : actual) {
        std::sort(vec.begin(), vec.end());
    }

    ASSERT_EQ(expected, actual);
}

TEST_F(CombinationTest, TestCombineWithN5K3) {
    std::vector<std::vector<int>> expected{{1, 2, 3}, {1, 2, 4}, {1, 2, 5},
                                           {1, 3, 4}, {1, 3, 5}, {1, 4, 5},
                                           {2, 3, 4}, {2, 3, 5}, {2, 4, 5},
                                           {3, 4, 5}};
    std::vector<std::vector<int>> actual = solution.combine(5, 3);

    // 对结果进行排序以便比较
    std::sort(actual.begin(), actual.end());
    for (auto &vec : actual) {
        std::sort(vec.begin(), vec.end());
    }

    ASSERT_EQ(expected, actual);
} */

int main(int argc, char **argv)
{
    /*     ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS(); */
    int n = 4, k = 2;
    Solution solution;
    vector<vector<int>> result = solution.combine(n, k);
    for (auto &vec : result)
    {
        for (auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
