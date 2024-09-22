// 257. 二叉树的所有路径
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.*/
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
    void traversal(TreeNode *node, vector<int> &path, vector<string> &result)
    {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (node->left)
        {
            traversal(node->left, path, result);
            path.pop_back();
        }
        if (node->right)
        {
            traversal(node->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> path;
        vector<string> result;
        if (root == nullptr)
            return result;
        traversal(root, path, result);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution s;
    vector<string> result = s.binaryTreePaths(root);
    for (auto item : result)
    {
        cout << item << endl;
    }
    return 0;
}
