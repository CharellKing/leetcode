class Solution {
public:
    long long int pack_key(int row, int col) {
        return ((long long int)(row)) << 32 | col;
    }
    
    bool is_end(unordered_set<long long int>& traversed_pts, int row, int col, int k, int n) {
        return row < 0 || row >= n || col < 0 || col >= n || traversed_pts.find(pack_key(row, col)) != traversed_pts.end() || k > n* n;    
    }
    
    void right(vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, int& row, int& col, int& k, int n) {
        while (false == is_end(traversed_pts, row, col, k, n)) {
            matrix[row][col] = k;
            traversed_pts.insert(pack_key(row, col));
            k ++;
            col ++;
        }
        col --;
    }
    
    void down(vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, int& row, int& col, int& k, int n) {
        while (false == is_end(traversed_pts, row, col, k, n)) {
            matrix[row][col] = k;
            traversed_pts.insert(pack_key(row, col));
            k ++;
            row ++;
        }
        row --;
    }

    void left(vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, int& row, int& col, int& k, int n) {
        while (false == is_end(traversed_pts, row, col, k, n)) {
            matrix[row][col] = k;
            traversed_pts.insert(pack_key(row, col));
            k ++;
            col --;
        }
        col ++;
    }

    void up(vector<vector<int>>& matrix, unordered_set<long long int>& traversed_pts, int& row, int& col, int& k, int n) {
        while (false == is_end(traversed_pts, row, col, k, n)) {
            matrix[row][col] = k;
            traversed_pts.insert(pack_key(row, col));
            k ++;
            row --;
        }
        row ++;
    }


    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(n, 0));
        unordered_set<long long int> traversed_pts;
        int k = 1;
        int total = n * n;
        int row = 0, col = 0;
        while (k <= total) {
            right(matrix, traversed_pts, row, col, k, n);
            row ++;
            down(matrix, traversed_pts, row, col, k, n);
            col --;
            left(matrix, traversed_pts, row, col, k, n);
            row --;
            up(matrix, traversed_pts, row, col, k, n);
            col ++;
        }
        return matrix;
    }
};
