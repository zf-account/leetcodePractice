/* ----------------环形链表思路---------------- */
//  1.快慢指针，快指针每次走两步，慢指针每次走一步，如果有环，快慢指针一定会相遇，否则快指针会先到达尾部，返回nullptr
//  2.确定环入口的位置: 快慢指针相遇后，让一个指针从head开始，另一个从相遇点开始，再次相遇的位置就是环的入口(可以看代码随想录数学证明)
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
    ListNode():val(0),next(nullptr){}
};

class Solution
{
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* ptmp1 = fast;
                ListNode* ptmp2 = head;
                while (ptmp1 != ptmp2) {
                    ptmp1 = ptmp1->next;
                    ptmp2 = ptmp2->next;
                }
                return ptmp1;
            }
        }
        return nullptr;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
