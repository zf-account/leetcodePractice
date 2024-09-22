#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root == nullptr)
            return nullptr;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                Node* node = que.front();
                que.pop();
                if (size == 0) // 最后一个节点，注意这里是size==0而不是size==1
                    node->next = nullptr;
                else
                    node->next = que.front();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* re=Solution().connect(root);
    cout << re->next << endl;
    cout << re->left->next << endl;
    cout << re->right->next << endl;
    cout << re->left->left->next << endl;
    cout << re->left->right->next << endl;
    cout << re->right->left->next << endl;
    cout << re->right->right->next << endl;
    return 0;
}
