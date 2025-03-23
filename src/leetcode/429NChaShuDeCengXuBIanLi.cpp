// 429.N叉树的层序遍历
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            while (size--) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (Node* ele : node->children) {
                    que.push(ele);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

// Function to create a test tree
Node* createTestTree() {
    Node* root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    return root;
}
// Main function to test the levelOrder function
int main() {
    Node* root = createTestTree();
    vector<vector<int>> result = Solution().levelOrder(root);

    // Print the result
    for (const auto& vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete root->children[0]->children[0];
    delete root->children[0]->children[1];
    delete root->children[0];
    delete root->children[1];
    delete root->children[2];
    delete root;

    return 0;
}
