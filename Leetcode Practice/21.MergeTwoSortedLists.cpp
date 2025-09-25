#include <iostream>
using namespace std;

struct ListNode {
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        node temp(0);
        node* tail = &temp;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                tail->next = new node(list1->val);
                list1 = list1->next;
            }
            else
            {
                tail->next = new node(list2->val);
                list2 = list2->next;
            }
            tail = tail->next;
        }

        while(list1 != NULL)
        {
            tail->next = new node(list1->val);
            list1 = list1->next;
            tail = tail->next;
        }
        while(list2 != NULL)
        {
            tail->next = new node(list2->val);
            list2 = list2->next;
            tail = tail->next;
        }
        return temp.next;
    }
};