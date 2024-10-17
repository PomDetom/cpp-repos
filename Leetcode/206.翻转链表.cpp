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
    ListNode* reverseList(ListNode* head) {
        
        //迭代
        ListNode* tail = nullptr;
        ListNode* newhead = head;

        while (newhead)
        {
            ListNode* next = newhead->next;
            newhead->next = tail;
            tail = newhead;
            newhead = next;
        }

        return tail;
        //递归
        // if (head == nullptr || head->next == nullptr)
        // {
        //     return head;
        // }
        // ListNode* newhead = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        // return newhead;
    }
};