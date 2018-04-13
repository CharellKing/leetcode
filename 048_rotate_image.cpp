class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 沿着对角线翻转
        for(int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix.size() - i - 1; j ++) {
                swap(matrix[i][j], matrix[matrix.size() - j - 1][matrix.size() - i - 1]);
            }
        }
        
        // 沿着中间横线翻转
        for(int i = 0; i < (matrix.size() >> 1); i ++) {
            for(int j = 0; j < matrix.size(); j ++) {
                swap(matrix[i][j], matrix[matrix.size() - i - 1][j]);
            }
        }
    }
};