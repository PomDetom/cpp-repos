class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min = 0;
        int max = 0;
        int ret = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < prices[min])
            {
                min = i;
            }
            else if (prices[i] > prices[min])
            {
                max = i;
                if (prices[max] - prices[min] > ret)
                {
                    ret = prices[max] - prices[min];
                }
            }
        }

        return ret;
    }
};