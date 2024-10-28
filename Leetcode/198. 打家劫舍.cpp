class Solution {
public:
    //递归
    // std::vector<int> memo;
    // int rec(vector<int>& nums, int n)
    // {
    //     if (n < 0)
    //     {
    //         return 0;
    //     }
    //     if (memo[n] != -1)
    //     {
    //         return memo[n];
    //     }
    //     else
    //     {
    //         return memo[n] = max(rec(nums, n-1),rec(nums, n-2)+nums[n]);
    //     }
    // }

    int rob(vector<int>& nums) {
        
        //递归
        // memo.resize(nums.size() + 1, -1);
        // return rec(nums, nums.size() - 1);
        
        //迭代
        int i = 0;
        int j = 0;

        for (int value = 0; value < nums.size(); ++value)
        {
            int result = max(j, i + nums[value]);
            i = j;
            j = result;
        }

        return j;
    }
};