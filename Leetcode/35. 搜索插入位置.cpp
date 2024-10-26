class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int front = -1;
        int tail = nums.size();
        int middle = 0;

        while (front + 1 < tail)
        {
            middle = (front + tail) / 2;

            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] < target)
            {
                front = middle;
            }
            else
            {
                tail = middle;
            }
        }
        
        return tail;
    }
};