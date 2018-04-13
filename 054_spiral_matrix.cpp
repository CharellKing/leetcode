class Solution {
public:
    long long int pack_key(int a, int b) {
        return ((long long int)(a)) << 32 | b;    
    }
    
    bool is_end(const vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, int row, int col) {
        return row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || traversed_pts.end() != traversed_pts.find(pack_key(row, col));    
    }
    
    void right(const vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, vector<int>& ret, int& row, int& col) {
        while (false == is_end(matrix, traversed_pts, row, col)) {
            traversed_pts.insert(pack_key(row, col));
            ret.push_back(matrix[row][col]);
            col ++;
        }
        col --;
    }
    
    void down(const vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, vector<int>& ret, int& row, int& col) {
        while (false == is_end(matrix, traversed_pts, row, col)) {
            traversed_pts.insert(pack_key(row, col));
            ret.push_back(matrix[row][col]);
            row ++;
        }
        row --;
    }
    
    void left(const vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, vector<int>& ret, int& row, int& col) {
        while (false == is_end(matrix, traversed_pts, row, col)) {
            traversed_pts.insert(pack_key(row, col));
            ret.push_back(matrix[row][col]);
            col --;
        }
        col ++;
    }
    
    void up(const vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, vector<int>& ret, int& row, int& col) {
        while (false == is_end(matrix, traversed_pts, row, col)) {
            traversed_pts.insert(pack_key(row, col));
            ret.push_back(matrix[row][col]);
            row --;
        }
        row ++;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return vector<int>();
        }
        
        vector<int> ret;
        unordered_set<long long int> traversed_pts;
        int row = 0, col = 0;
        while (ret.size() < matrix.size() * matrix[0].size()) {
           right(matrix, traversed_pts, ret, row, col);
           row ++;
           down(matrix, traversed_pts, ret, row, col);
           col --;
           left(matrix, traversed_pts, ret, row, col);
           row --;
           up(matrix, traversed_pts, ret, row, col);
           col ++;
        }
        return ret;
    }
};
