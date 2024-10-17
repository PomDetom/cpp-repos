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
    bool hasCycle(ListNode *head) {
        
        //双指针
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
        //更改链表的next指向
        // if (head == nullptr || head->next == nullptr)
        // {
        //     return false;
        // }

        // ListNode* rep = new ListNode(0, head);

        // while (head != nullptr)
        // {
        //     if (head == rep)
        //     {
        //         return true;
        //     }
        //     ListNode* next = head->next;
        //     head->next = rep;
        //     head = next;
        // }

        // return false;
    }
};