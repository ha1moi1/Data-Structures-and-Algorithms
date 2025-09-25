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

typedef ListNode node;

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        node temp(0);
        node* tail = &temp;

        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            tail->next = new node(sum % 10);
            tail = tail->next;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }

        return temp.next;
    }
};