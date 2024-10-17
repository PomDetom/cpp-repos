/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tailA = headA;
        ListNode* tailB = headB;
        int countA = 0;
        int countB = 0;

        while (tailA)
        {
            ++countA;
            tailA = tailA->next;
        }
        while (tailB)
        {
            ++countB;
            tailB = tailB->next;
        }

        tailA = headA;
        tailB = headB;

        if (countA > countB)
        {
            for (int i = 0; i < countA - countB; i++)
            {
                tailA = tailA->next;
            }
        }
        else if (countB > countA)
        {
            for (int i = 0; i < countB - countA; i++)
            {
                tailB = tailB->next;
            }
        }

        while (tailA != NULL)
        {
            if (tailA == tailB)
            {
                return tailA;
            }
            else
            {
                tailA = tailA->next;
                tailB = tailB->next;
            }
        }

        return NULL;
    }
};