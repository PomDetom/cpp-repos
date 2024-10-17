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
    bool isPalindrome(ListNode* head) {

        ListNode* tail = head;
        ListNode* middle = nullptr;

        int count = 0;

        while (tail)
        {
            ++count;
            tail = tail->next;
        }

        for (int i = 0; i < (count+1)/2; i++)
        {
            ListNode* next = head->next;
            head->next = middle;
            middle = head;
            head = next;
        }

        if (count == 1)
        {
            return true;
        }
        else if (count % 2 == 0)
        {
            while (middle->val == head->val)
            {
                if (middle->next == nullptr)
                {
                    return true;
                }
                middle = middle->next;
                head = head->next;
            }
        }
        else
        {
            middle = middle->next;
            while (middle->val == head->val)
            {
                if (middle->next == nullptr)
                {
                    return true;
                }
                middle = middle->next;
                head = head->next;
            }
        }

        return false;
    }
};