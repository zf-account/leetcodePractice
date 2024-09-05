#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 先对两个列表进行倒序排列，再使用之前的方法做，最后对生成的结果倒序
class Solution {
public:
    void reverse(ListNode* &l) {
        if (l == nullptr) {
            cout << "empty linked list" << endl;
        } else {
            ListNode *current, *prev, *next;
            current = l;
            prev = nullptr;
            while (current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            l = prev;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(l1);
        reverse(l2);
        int sum_next = 0;
        ListNode* result = new ListNode();
        ListNode* pcur = result;
        while (l1 != nullptr || l2 != nullptr || sum_next != 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + sum_next;
            pcur->next = new ListNode(sum % 10);
            pcur = pcur->next;
            sum_next = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        reverse(result->next);
        return result->next;
    }
};
int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution su;
    ListNode* result = su.addTwoNumbers(l1, l2);
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
