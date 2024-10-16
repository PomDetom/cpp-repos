///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//
//        ListNode* front = new ListNode(-1, head);
//        ListNode* tail = front;
//
//        while (tail->next)
//        {
//            if (tail->next->val == val)
//            {
//                if (tail->next->next == nullptr)
//                {
//                    tail->next = nullptr;
//                }
//                else
//                {
//                    ListNode* del = tail->next;
//                    tail->next = tail->next->next;
//                    del = nullptr;
//                }
//            }
//            else
//            {
//                tail = tail->next;
//            }
//        }
//
//        return front->next;
//    }
//};