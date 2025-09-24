#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *link;
    ListNode() : data(0), link(nullptr) {}
    ListNode(int x) : data(x), link(nullptr) {}
    ListNode(int x, ListNode *link) : data(x), link(link) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int num1, num2, result;
        num1 = getListResult(l1);
        num2 = getListResult(l2);
        result = num1 + num2;
        ListNode* result;
        while(result != 0)
        {
            
        }
    }

    int getListResult(ListNode* l)
    {
        int result = 0;
        while(l != NULL)
        {
            result = result + l->data;
            if(l->link == NULL) return result;
            result *= 10;
            l = l->link;
        }
        return result;
    }
};