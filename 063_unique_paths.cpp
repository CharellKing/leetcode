class Solution {
public:
    long long int pack_key(int row, int col) {
        return ((long long int)(row) << 32) | col;
    }
    
    void unpack_key(long long int key, int& row, int& col) {
        row = key >> 32;
        col = key & 0xffffffff;
    }
    
    bool is_valid(const vector<vector<int>>& obstacleGrid, int row, int col) {
        return row >= 0 && row < obstacleGrid.size() && col >= 0 && col < obstacleGrid[0].size() && 0 == obstacleGrid[row][col];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int total_num = 0, row = 0, col = 0;
        if (obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0) {
            return 0;
        }

        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        if (obstacleGrid[row - 1][col - 1] == 1 || 1 == obstacleGrid[0][0]) {
            return 0;
        }

        if (1 == row && 1 == col) {
            return 1;
        }

        unordered_map<long long int, int> one, two;
        unordered_map<long long int, int> &cur_layer = one, &next_layer = two;
        cur_layer.insert(make_pair(pack_key(0, 0), 1));
        
        int direction[2][2] = {{0, 1}, {1, 0}};
        int sum = 0;
        while (cur_layer.size() > 0) {
            for(unordered_map<long long int, int>::iterator iter = cur_layer.begin(); cur_layer.end() != iter; iter ++) {
                int cur_row = 0, cur_col = 0, next_row = 0, next_col = 0;
                unpack_key(iter->first, cur_row, cur_col);
                for(int i = 0; i < 2; i ++) {
                    next_row = cur_row + direction[i][0];
                    next_col = cur_col + direction[i][1];
                    if (is_valid(obstacleGrid, next_row, next_col)) {
                        long long int key = pack_key(next_row, next_col);
                        unordered_map<long long int, int>::iterator find_iter = next_layer.find(key);
                        if (find_iter == next_layer.end()) {
                            find_iter = next_layer.insert(make_pair(key, 0)).first;
                        }
                        find_iter->second += iter->second;
                    }
                }
            }
            
            long long int key = pack_key(row - 1, col - 1);
            unordered_map<long long int, int>::iterator iter = next_layer.find(key);
            if (iter != next_layer.end()) {
                sum += iter->second;
            }
            swap(cur_layer, next_layer);
            next_layer.clear();
        }

        return sum;
    }
};

