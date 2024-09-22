#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode*left,TreeNode * right):val(x),left(left),right(right){}
};

class Solution
{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1)
            return root2;
        if (!root2)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
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
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);
    root1->right->right = new TreeNode(4);
    TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    TreeNode* result = Solution().mergeTrees(root1, root2);
    printTreeNode().printPreorderTraversal(result);
    printTreeNode().printInorderTraversal(result);
    printTreeNode().printPostorderTraversal(result);
    return 0;
}

