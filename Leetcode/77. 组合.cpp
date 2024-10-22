class Solution {
public:
    vector<vector<int>> comb;
    vector<int> part;

    void backtracking(int n, int k, int startRoot)
    {
        if (part.size() == k)
        {
            comb.push_back(part);
            return;
        }

        for (int i = startRoot; i <= (n+part.size()-k+1); i++)
        {
            part.push_back(i);
            backtracking(n, k, i + 1);
            part.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        backtracking(n, k, 1);
        
        return comb;
    }
};