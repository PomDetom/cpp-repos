class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int pos = 0;
        int i = 0;

        for (; i < nums.size() && pos >= i; i++)
        {
            pos = max(pos, i + nums[i]);
        }

        if (i == nums.size())
            return true;
        else    
            return false;
    }
};