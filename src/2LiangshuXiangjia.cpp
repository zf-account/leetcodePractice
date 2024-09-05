/* 递归、链表、数学*/
#include <iostream>
#include <cmath>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 1.迭代解法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* pcur = result;
        int sum_next = 0;
        while (l1 != nullptr || l2 != nullptr || sum_next != 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + sum_next;
            pcur->next = new ListNode(sum % 10);
            pcur = pcur->next;
            sum_next=sum/10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return result->next;
    }
};
// // 2.迭代解法
// class Solution {
// public:
//     // l1 和 l2 为当前遍历的节点，carry 为进位
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0) {
//         if (l1 == nullptr && l2 == nullptr) // 递归边界：l1 和 l2 都是空节点
//             return carry ? new ListNode(carry) : nullptr; // 如果进位了，就额外创建一个节点
//         if (l1 == nullptr) // 如果 l1 是空的，那么此时 l2 一定不是空节点
//             swap(l1, l2); // 交换 l1 与 l2，保证 l1 非空，从而简化代码
//         carry += l1->val + (l2 ? l2->val : 0); // 节点值和进位加在一起
//         l1->val = carry % 10; // 每个节点保存一个数位
//         l1->next = addTwoNumbers(l1->next, (l2 ? l2->next : nullptr), carry / 10); // 进位
//         return l1;
//     }
// };
int main(int argc, char *argv[])
{

    int num1 = 9999999;
    int num2 = 9999;
    int sum = num1 + num2;
    Solution su;
    // ListNode* phead = su.addTwoNumbers(sum);
    // while (phead != NULL)
    // {
    //     cout << phead->val << endl;
    //     phead = phead->next;
    // }
    return 0;
}
