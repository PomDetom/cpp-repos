class Solution {
public:
    vector<vector<int>> comb;
    vector<int> part;
    int sum = 0;

    void backtracking(vector<int>& candidates, int target, int pos, int& sum)
    {
        if (sum == target)
        {
            comb.push_back(part);
            return;
        }

        for (int i = pos; i < candidates.size() && sum < target - 1; i++)
        {
            sum += candidates[i];
            part.push_back(candidates[i]);
            backtracking(candidates, target, i, sum);
            sum -= candidates[i];
            part.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        if (target < 2)
        {
            return comb;
        }
        
        backtracking(candidates, target, 0, sum);
           
        return comb;
    }
};