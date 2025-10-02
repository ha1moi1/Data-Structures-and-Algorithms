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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        node dummy(0);
        node* tail = &dummy;

        while(head != NULL)
        {
            if(tail->val != )
        }
    }
};