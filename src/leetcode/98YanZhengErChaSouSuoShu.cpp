#include <iostream>
#include <vector>
#include <cassert>


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
    TreeNode *pre = nullptr;

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        bool left = isValidBST(root->left);
        if (pre && pre->val >= root->val)
        {
            return false;
        }
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};

// Function to test the isValidBST function
void testIsValidBST()
{
    Solution solution;

    // Create nodes for the tree
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node9 = new TreeNode(9);

    // Construct the tree
    TreeNode *root = new TreeNode(6);
    root->left = node3;
    root->right = node8;
    node3->left = node1;
    node3->right = node4;
    node8->left = node7;
    node8->right = node9;
    node4->left = node5;

    // Test cases
    assert(solution.isValidBST(root) == true); // The tree should be a valid BST

    // Clean up memory
    delete root;
    delete node5;
    delete node3;
    delete node8;
    delete node1;
    delete node4;
    delete node7;
    delete node9;
}
int main(int argc, char const *argv[])
{
    testIsValidBST();
    cout << "All test cases passed!" << endl;
    return 0;
}
