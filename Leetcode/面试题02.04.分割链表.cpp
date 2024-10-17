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
    ListNode* partition(ListNode* head, int x) {

        ListNode* greater = new ListNode();
        ListNode* less = new ListNode();
        ListNode* newhead = less;
        ListNode* newtail = greater;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                less->next = head;
                head = head->next;
                less = less->next;
            }
            else
            {
                greater->next = head;
                head = head->next;
                greater = greater->next;
            }
        }
        greater->next = nullptr;
        less->next = newtail->next;

        return newhead->next;
    }
};