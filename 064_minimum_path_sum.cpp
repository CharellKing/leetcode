class Solution {
public:
    long long int pack_key(int row, int col) {
        return ((long long int)(row) << 32) | col;
    }
    
    void unpack_key(long long int key, int& row, int& col) {
        row = key >> 32;
        col = key & 0xffffffff;
    }
    
    bool is_valid(int row, int col, int cur_row, int cur_col) {
        return cur_row >= 0 && cur_row < row && cur_col >= 0 && cur_col < col;    
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() <= 0 || grid[0].size() <= 0) {
            return 0;
        }
        
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> sum = vector<vector<int>>(row, vector<int>(col, INT_MAX));
        unordered_set<long long int> one, two;
        unordered_set<long long int> &cur = one, &next = two;
        int directions[2][2] = {{0, 1}, {1, 0}};
        cur.insert(pack_key(0, 0));
        sum[0][0] = grid[0][0];
        while (cur.size() > 0) {
            for(unordered_set<long long int>::iterator iter = cur.begin(); cur.end() != iter; iter ++) {
                int cur_row = 0, cur_col = 0;
                unpack_key(*iter, cur_row, cur_col);
                for(int j = 0; j < 2; j ++) {
                    int next_row = cur_row + directions[j][0];
                    int next_col = cur_col + directions[j][1];
                    if (is_valid(row, col, next_row, next_col)) {
                        int val = sum[cur_row][cur_col] + grid[next_row][next_col];
                        if (sum[next_row][next_col] > val) {
                            sum[next_row][next_col] = val;
                        }
                        next.insert(pack_key(next_row, next_col));
                    }
                }
            }
            
            swap(cur, next);
            next.clear();
        }
        return sum[row - 1][col - 1];
    }
};
