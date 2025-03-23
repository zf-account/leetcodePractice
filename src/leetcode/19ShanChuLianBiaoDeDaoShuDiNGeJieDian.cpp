// 注意这一题的思想很有趣:如果要删除倒数n个节点,那么如何找到倒数第n个节点呢?
// 使用两个指针,一个指针先走n步,然后两个指针一起走,当第一个指针到达末尾时,第二个指针指向要删除的节点
// 因为删除节点,所以需要记录前一个节点,所以需要一个快指针比n多走一步
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *fast = dummyHead;
        ListNode *slow = dummyHead;
        n = n + 1; //n为什么要加1？因为如果快指针比慢指针先走n步，那么快指针走向nullptr时，慢指针刚好指向倒数第n个节点，而要删除倒数第n个节点，必须将指针指向倒数第n个节点的前一个节点，所以要多走一步
        while (n--&&fast!=nullptr)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *ptmp = slow->next;
        slow->next = slow->next->next;
        delete ptmp;
    
    return dummyHead->next;}
};
int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;
    Solution su;
    ListNode *re = su.removeNthFromEnd(head, n);
    while (re)
    {
        cout << re->val << " ";
        re = re->next;
    }
    cout << endl;
    return 0;
}
