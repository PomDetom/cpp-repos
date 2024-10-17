/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //双指针
        ListNode* tail = head;
        ListNode* newhead = new ListNode(0, head);
        head = newhead;
        for (int i = 0; i < n; i++)
        {
            tail = tail->next;
        }
        while (tail)
        {
            tail = tail->next;
            head = head->next;
        }
        head->next = head->next->next;

        return newhead->next;
    }
};