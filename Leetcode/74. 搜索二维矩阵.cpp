class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int list = matrix[0].size();
        int front = -1;
        int tail = matrix.size() * list;
        int middle = 0;
        int middle_value = 0;

        while (front + 1 < tail)
        {
            middle = (front + tail) / 2;
            middle_value = matrix[middle / list][middle % list];

            if (middle_value == target)
            {
                return true;
            }
            else if (middle_value < target)
            {
                front = middle;
            }
            else
            {
                tail = middle;
            }
        }

        return false;
    }
};