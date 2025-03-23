/**
  Definition for singly-linked list.
  */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/* ---------------------------------------- 双指针写法 -------------------------------------- */
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         ListNode *cur = head;
//         ListNode *pre = nullptr;
//         while (cur)
//         {
//             ListNode *ptmp = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = ptmp;
//         }
//         return pre;
//     }
// };
/* ---------------------------------------- 递归写法 -------------------------------------- */
class Solution {
public:
    ListNode* reverse(ListNode* cur, ListNode* pre) {
        if (cur == nullptr)
            return pre;
        ListNode* ptmp = cur->next;
        cur->next = pre;
        return reverse(ptmp, cur);
    }
    ListNode* reverseList(ListNode* head) { return reverse(head, nullptr); }
};
int main(int argc, char const *argv[])
{

    return 0;
}
