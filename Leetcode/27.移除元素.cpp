//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//
//        int nums_length = nums.size();
//        int front = 0;
//        int tail = nums_length;
//
//        while (front < tail)
//        {
//            if (nums[front] == val)
//            {
//                nums[front] = nums[tail - 1];
//                --tail;
//            }
//            else
//            {
//                ++front;
//            }
//        }
//
//        return front;
//    }
//};