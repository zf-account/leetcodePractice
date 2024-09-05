// 注意的点
//  1.如果要操作两个节点，则当前指针一定要指向这两个节点的前一个节点，因此必须使用虚头节点
//  2.在操作节点之前，一定要保存节点的下一节点的地址，否则节点一定变更，会丢失下一节点的地址
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
};

using namespace std;
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur -> next != nullptr&& cur->next->next != nullptr)//这里注意，cur->next一定要写在前面，否则万一cur->next为空，则cur->next->next就会报错
        {
            ListNode *ptmp1 = cur->next;
            ListNode *ptmp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = ptmp1;
            cur->next->next->next = ptmp2;
            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};

int main(int argc, char const *argv[])
{
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution su;
    ListNode* re=su.swapPairs(head);
    while(re!=nullptr){
        cout<<re->val<<" ";
        re=re->next;
    }
    return 0;
}
