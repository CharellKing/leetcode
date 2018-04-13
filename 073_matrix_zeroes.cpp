class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return;    
        }
        
        vector<int> row_flags = vector<int>(matrix.size(), 1);
        vector<int> col_flags = vector<int>(matrix[0].size(), 1);
        
        for(int i = 0; i < row_flags.size(); i ++) {
            for(int j = 0; j < col_flags.size(); j ++) {
                if (0 == matrix[i][j]) row_flags[i] = 0;
            }
        }
        
        for(int j = 0; j < col_flags.size(); j ++) {
            for(int i = 0; i < row_flags.size(); i ++) {
                if (0 == matrix[i][j]) col_flags[j] = 0;
            }
        }
        
        for(int i = 0; i < row_flags.size(); i ++) {
            for(int j = 0; j < col_flags.size(); j ++) {
                if (0 == (row_flags[i] & col_flags[j])) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
