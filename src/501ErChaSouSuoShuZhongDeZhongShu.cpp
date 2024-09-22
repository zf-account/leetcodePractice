#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
    int count = 0, maxCount = 0;
    TreeNode *pre = nullptr;
    vector<int> result;

public:
    void searchBST(TreeNode *cur)
    {
        if (!cur)
            return;
        searchBST(cur->left);
        if (!pre)
        {
            count = 1;
        }
        else if (cur->val == pre->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        pre = cur;
        if (count == maxCount)
        {
            result.push_back(cur->val);
        }
        else if (count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        searchBST(cur->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        searchBST(root);
        return result;
    }
};
int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    vector<int> result = Solution().findMode(root);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
