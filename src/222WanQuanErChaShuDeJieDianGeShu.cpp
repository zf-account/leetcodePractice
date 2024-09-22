// 这道题可以用普通思路来写，时间上更快一些的方法是在完全二叉树中找满二叉树，对于满二叉树，其节点数量=2^d-1，d为树的深度
#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftdepth = 0, rightdepth = 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        while (left)
        {
            left = left->left;
            leftdepth++;
        }
        while (right)
        {
            right = right->right;
            rightdepth++;
        }
        if (leftdepth == rightdepth)
            return (2 << leftdepth) - 1;
        int leftnum = countNodes(root->left);
        int rightnum = countNodes(root->right);
        return leftnum + rightnum + 1;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<Solution().countNodes(root)<<endl;
    return 0;
}
