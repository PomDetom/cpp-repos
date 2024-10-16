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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//
//        int sum = 0;
//        int count = 0;
//
//        ListNode* l3 = new ListNode;
//        ListNode* tailList = l3;
//
//        while (l1 != nullptr || l2 != nullptr || count != 0)
//        {
//            tailList->next = new ListNode;
//            tailList = tailList->next;
//            sum += count;
//            count = 0;
//            if (l1 != nullptr)
//            {
//                sum += (l1->val);
//                l1 = l1->next;
//            }
//            if (l2 != nullptr)
//            {
//                sum += (l2->val);
//                l2 = l2->next;
//            }
//            if (sum > 9)
//            {
//                count += sum / 10;
//                sum %= 10;
//            }
//
//            tailList->val = sum;
//            sum = 0;
//        }
//
//        return l3->next;
//    }
//};