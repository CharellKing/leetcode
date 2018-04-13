class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return false;
        }
        
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            int i = row;
            while (i < matrix.size()) {
                if (target < matrix[i][col]) {
                      break;
                } else if (target == matrix[i][col]) {
                    return true;
                }
                i ++;
            }
            row = i;
            col --;
        }
        return false;
    }
};
