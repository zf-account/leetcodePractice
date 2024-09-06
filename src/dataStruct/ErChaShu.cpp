#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
public:
    // 前序遍历递归写法
    void pretraversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
            return;
        vec.push_back(cur->val);
        pretraversal(cur->left, vec);
        pretraversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> re;
        pretraversal(root, re);
        return re;
    }
    // 中序遍历递归写法
    void inotraversal(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
        {
            return;
        }
        inotraversal(cur->left, vec);
        vec.push_back(cur->val);
        inotraversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> re;
        inotraversal(root, re);
        return re;
    }
    // 后续遍历递归写法
    void postraversla(TreeNode *cur, vector<int> &vec)
    {
        if (cur == nullptr)
        {
            return;
        }
        postraversla(cur->left, vec);
        postraversla(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> re;
        postraversla(root, re);
        return re;
    }

    // 前序遍历迭代写法
    vector<int> dpreorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == NULL)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top(); // 中
            st.pop();
            result.push_back(node->val);
            if (node->right)
                st.push(node->right); // 右（空节点不入栈）
            if (node->left)
                st.push(node->left); // 左（空节点不入栈）
        }
        return result;
    }
    // 中序遍历迭代写法
    vector<int> dinorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        TreeNode *cur = root;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            cur = cur->right;
        return result;
        }
    }
    // 后序遍历迭代写法
    vector<int> dpostorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if(root==nullptr)
            return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution su;
    cout << "---------------------递归-----------------------" << endl;
    vector<int> PreorderTraversal = su.preorderTraversal(root);
    for (const int &i : PreorderTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> InorderTraversal = su.inorderTraversal(root);
    for (const int &i : InorderTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> PostorderTraversal = su.postorderTraversal(root);
    for (const int &i : PostorderTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "---------------------迭代-----------------------" << endl;
    vector<int> dpreorderTraversal = su.preorderTraversal(root);
    for (const int &i : dpreorderTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> dInorderTraversal = su.inorderTraversal(root);
    for (const int &i : dInorderTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> dPostorderTraversal = su.postorderTraversal(root);
    for (const int &i : dPostorderTraversal)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
