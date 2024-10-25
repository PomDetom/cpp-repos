class Solution {
public:
    // std::vector<int> memo;

    // //递归
    // int climbRecur(int n)
    // {
    //     if (n < 2)
    //     {
    //         return 1;
    //     }

    //     int& ret = memo[n];
    //     if (ret != 0)
    //     {
    //         return ret;
    //     }
        
    //     return ret = climbRecur(n - 1) + climbRecur(n - 2);
    // }

    int climbStairs(int n) {
        
        // //递归
        // memo.resize(n + 1);
        // return climbRecur(n);

        //迭代
        int first = 0;
        int second = 1;
        int next = 0;

        for (int i = 1; i <= n; i++)
        {
            next = first + second;
            first = second;
            second = next;
        }

        return next;
    }
};