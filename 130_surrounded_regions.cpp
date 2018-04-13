class Solution {
public:
    long long int pack_key(int row, int col) {
        return ((long long int)(row) << 32) | col;
    }

    bool is_outer(const vector<vector<char>>& board, int row, int col) {
        return row == board.size() - 1 || row == 0 || col == 0 || col == board[0].size() - 1;
    }

    bool is_valid(const vector<vector<char>>& board, int row, int col, const unordered_set<long long int>& used_posed) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && 'O' == board[row][col] && used_posed.end() == used_posed.find(pack_key(row, col));
    }

    bool find_letter(const vector<vector<char>>& board, int row, int col, unordered_set<long long int>& used_poses, vector<pair<int, int>>& pts) {
        vector<pair<int, int>> one_layer, two_layer;
        vector<pair<int, int>> &cur_layer = one_layer, &next_layer = two_layer;
        cur_layer.push_back(make_pair(row, col));
        used_poses.insert(pack_key(row, col));
        bool is_filled = true;
        while (cur_layer.size() > 0) {
            for(int i = 0; i < cur_layer.size(); i ++) {
                pts.push_back(make_pair(cur_layer[i].first, cur_layer[i].second));

                if (is_outer(board, cur_layer[i].first, cur_layer[i].second)) {
                    is_filled = false;
                }

                //left
                int new_row = cur_layer[i].first, new_col = cur_layer[i].second - 1;
                if (is_valid(board, new_row, new_col, used_poses)) {
                    next_layer.push_back(make_pair(new_row, new_col));
                    used_poses.insert(pack_key(new_row, new_col));
                }

                //right
                new_row = cur_layer[i].first, new_col = cur_layer[i].second + 1;
                if (is_valid(board, new_row, new_col, used_poses)) {
                    next_layer.push_back(make_pair(new_row, new_col));
                    used_poses.insert(pack_key(new_row, new_col));
                }

                //up
                new_row = cur_layer[i].first - 1, new_col = cur_layer[i].second;
                if (is_valid(board, new_row, new_col, used_poses)) {
                    next_layer.push_back(make_pair(new_row, new_col));
                    used_poses.insert(pack_key(new_row, new_col));
                }

                //down
                new_row = cur_layer[i].first + 1, new_col = cur_layer[i].second;
                if (is_valid(board, new_row, new_col, used_poses)) {
                    next_layer.push_back(make_pair(new_row, new_col));
                    used_poses.insert(pack_key(new_row, new_col));
                }
            }
            swap(cur_layer, next_layer);
            next_layer.clear();
        }
        return is_filled;
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() <= 0 || board[0].size() <= 0) {
            return;
        }
        unordered_set<long long int> used_poses;
        for(int i = 0; i < board.size(); i ++) {
            for(int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == 'O' && used_poses.find(pack_key(i, j)) == used_poses.end()) {
                    vector<pair<int, int>> pts;
                    if (true == find_letter(board, i, j, used_poses, pts)) {
                        for(int k = 0; k < pts.size(); k ++) {
                            board[pts[k].first][pts[k].second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
