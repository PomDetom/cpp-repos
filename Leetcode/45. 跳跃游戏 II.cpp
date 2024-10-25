class Solution {
public:
    int jump(vector<int>& nums) {
        
        int len = nums.size();
        int pos = 0;
        int maxjump = 0;
        int count = 0;

        for (int i = 0; i < len && pos < len - 1; i++)
        {
            if (pos > i)
            {
                if (i + nums[i] > maxjump)
                {
                    maxjump = i + nums[i];
                }
            }
            else if (pos == i)
            {
                pos = max(i +nums[i], maxjump);
                maxjump = 0;
                count++;
            }
        }

        return count;
    }
};