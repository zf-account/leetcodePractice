#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){}
};
// 自己写的，再看看官方题解，要更简单一些
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        stack<int> s1, s2;
    while(list1){
            s1.push(list1->val);
            list1 = list1->next;
        }
        while (list2) {
            s2.push(list2->val);
            list2 = list2->next;
        }
        ListNode* result = nullptr;
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty() && !s2.empty()) {
                if (s1.top() >= s2.top()) {
                    ListNode* ptmp = new ListNode(s1.top());
                    ptmp->next = result;
                    result = ptmp;
                    s1.pop();
                } else {
                    ListNode* ptmp = new ListNode(s2.top());
                    ptmp->next = result;
                    result = ptmp;
                    s2.pop();
                }
            } else if (!s1.empty()) {
                ListNode* ptmp = new ListNode(s1.top());
                ptmp->next = result;
                result = ptmp;
                s1.pop();
            } else {
                ListNode* ptmp = new ListNode(s2.top());
                ptmp->next = result;
                result = ptmp;
                s2.pop();
            }
        }
        return result;
    }
};
int main(int argc, char *argv[])
{
    ListNode* l1=new ListNode(1);
    l1->next=new ListNode(2);
    l1->next->next=new ListNode(4);
    ListNode* l2=new ListNode(1);
    l2->next=new ListNode(3);
    l2->next->next=new ListNode(4);
    Solution su;
    ListNode* result=su.mergeTwoLists(l1, l2);
    while (result)
    {
        cout<<result->val<<" ";
        result=result->next;
    }
    
    return 0;
}
