#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 1)
            return new TreeNode(nums[0]);
        int maxValue = 0, index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(maxValue);
        if (index > 0)
        {
            vector<int> left(nums.begin(), nums.begin() + index);
            root->left = constructMaximumBinaryTree(left);
        }
        if (index < nums.size() - 1)
        {
            vector<int> right(nums.begin() + index + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};

// 输出结果
class printTreeNode
{
public:
// 前序遍历打印
    void printPreorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> re;
        if (root == nullptr)
            return;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            re.push_back(node->val);
            if (node->right)
            {
                st.push(node->right);
            }
            if (node->left)
            {
                st.push(node->left);
            }
        }
        for (const int &i : re)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // 中序遍历打印
    void inotraversal(TreeNode *root, vector<int> &re)
    {
        if (root == nullptr)
            return;
        inotraversal(root->left, re);
        re.push_back(root->val);
        inotraversal(root->right, re);
    }
    void printInorderTraversal(TreeNode *root)
    {
        vector<int> re;
        inotraversal(root, re);
        for (const int &i : re)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // 后续遍历打印
    void postraversal(TreeNode *root, vector<int> & re){
        if(root == nullptr)
            return;
            postraversal(root->left, re);
            postraversal(root->right, re);
            re.push_back(root->val);
    }
    void printPostorderTraversal(TreeNode *root){
        vector<int> re;
        postraversal(root, re);
        for(const int &i : re){
            cout << i << " ";
        }
        cout << endl;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution sol;
    TreeNode *result = sol.constructMaximumBinaryTree(nums);
    printTreeNode p;
    p.printPreorderTraversal(result);
    p.printInorderTraversal(result);
    p.printPostorderTraversal(result);
    return 0;
}
