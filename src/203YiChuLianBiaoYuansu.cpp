#include <iostream>

using namespace std;

struct LindekNode
{
    int val;
    LindekNode *next;
    LindekNode(int x) : val(x), next(NULL) {}
};
/* ---------------------------------------------------- 不使用虚拟头节点 ---------------------------------- */
// class Solution
// {
// public:
//     ListNode *removeElements(ListNode *head, int val)
//     {
//         while (head != nullptr && head->val == val)
//         {
//             ListNode *ptmp = head;
//             head = head->next;
//             delete ptmp;
//         }
//         ListNode *cur = head;
//         while (cur != nullptr && cur->next != nullptr)
//         {
//             if (cur->next->val == val)
//             {
//                 ListNode *ptmp = cur->next;
//                 cur->next = cur->next->next;
//                 delete ptmp; //注意这里如果删除了cur之后的元素，cur不需要向后移动，只有没有删除cur后面的元素，cur才需要向后移动
//             }
//             else
//                 cur = cur->next;
//         }
//         return head;
//     }
// };
/* ---------------------------------------------------- 使用虚拟头节点 ---------------------------------- */
class Solution {
public:
    LindekNode* removeElements(LindekNode* head, int val) {
        LindekNode* dummyHead = new LindekNode(val);
        dummyHead->next = head;
        LindekNode* cur = dummyHead; //注意起始位置
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                LindekNode* ptmp = cur->next;
                cur->next = cur->next->next;
                delete ptmp;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead->next; //注意返回位置
    }
};

int main(int argc, char const *argv[])
{
    int target = 6;
    LindekNode *head = new LindekNode(1);
    LindekNode *ptmp = head;
    for (int i = 0; i < 7; i++)
    {

        ptmp->next = new LindekNode(i);
        ptmp = ptmp->next;
    }
    LindekNode *ptr = Solution().removeElements(head, target);
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    return 0;
}
