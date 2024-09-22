#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        if (preorder.size() == 0)
            return nullptr;

        int rootValue = preorder[0];
        TreeNode *root = new TreeNode(rootValue);

        if (preorder.size() == 1)
            return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size();
             delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }
        vector<int> leftInorder(inorder.begin(),
                                inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1,
                                 inorder.end());

        vector<int> leftProrder(preorder.begin() + 1,
                                preorder.begin() + 1 + leftInorder.size());
        vector<int> rightProrder(preorder.begin() + 1 + leftInorder.size(),
                                 preorder.end());

        root->left = buildTree(leftProrder, leftInorder);
        root->right = buildTree(rightProrder, rightInorder);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    cout << root->val << endl;
    cout<<root->left->val<<endl;
    cout << root->right->val << endl;
    return 0;
}
