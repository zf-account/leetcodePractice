#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* ------------------------------------------ 迭代法 ------------------------------------- */
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (val > root->val)
            {
                root = root->right;
            }
            else if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};
/* --------------------------------------------------- 递归法 -------------------------------------------- */
class Solution2
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr || root->val == val)
        {
            return root;
        }
        TreeNode *result;
        if (val < root->val)
        {
            result = searchBST(root->left, val);
        }
        else if (val > root->val)
        {
            result = searchBST(root->right, val);
        }
        return result;
    }
};

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
    void postraversal(TreeNode *root, vector<int> &re)
    {
        if (root == nullptr)
            return;
        postraversal(root->left, re);
        postraversal(root->right, re);
        re.push_back(root->val);
    }
    void printPostorderTraversal(TreeNode *root)
    {
        vector<int> re;
        postraversal(root, re);
        for (const int &i : re)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    int val = 2;
    Solution su;
    TreeNode *ans = su.searchBST(root, val);
    printTreeNode pt;
    cout << "-------------迭代---------------" << endl;
    pt.printPreorderTraversal(ans);
    pt.printInorderTraversal(ans);
    pt.printPostorderTraversal(ans);
    cout << "-------------递归---------------" << endl;
    Solution2 su2;
    TreeNode *ans2 = su2.searchBST(root, val);
    pt.printPreorderTraversal(ans2);
    pt.printInorderTraversal(ans2);
    pt.printPostorderTraversal(ans2);

    return 0;
}
