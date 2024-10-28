class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        
        for (int n = 0; n < numRows; n++)
        {
            vector<int> row(n + 1, 1);

            for (int i = 1; i < n; i++)
            {
                row[i] = result[n-1][i] + result[n-1][i-1];
            }

            result.push_back(row);
        }

        return result;
    }
};