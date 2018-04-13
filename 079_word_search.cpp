#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;


struct Path {
    unordered_set<long long int> used_points;
    int cur_row, cur_col;
};

class Solution {
private:
    vector<Path> paths;
    // unordered_set<string> flags;
public:
    // string get_flag(int i, int j, int ith) {
    //     stringstream ss;
    //     ss << i << "-" << j << "-" << ith;
    //     return ss.str();
    // }
    
    long long int pack_key(int i, int j) {
        return (((long long int)(i)) << 32) | j;
    }
    
    void initialize(const vector<vector<char> >& board, char ch) {
        for(int i = 0; i < board.size(); i ++) {
            for(int j = 0; j < board[i].size(); j ++) {
                if (board[i][j] == ch) {
                    paths.push_back(Path());
                    Path& back = paths.back();
                    back.used_points.insert(pack_key(i, j));
                    back.cur_row = i;
                    back.cur_col = j;
                }
            }
        }
    }
    
    void get_next_poses(const vector<vector<char> >& board, const string& word, Path& path, vector<pair<int, int> >& next_poses) {
        if (path.used_points.size() < word.size()) {
            int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for(int i = 0; i < 4; i ++) {
                int row = path.cur_row + directions[i][0];
                int col = path.cur_col + directions[i][1];
                if (row >= 0 && row < board.size() && col >= 0 && col < board[1].size() && word[path.used_points.size()] == board[row][col] && path.used_points.end() == path.used_points.find(pack_key(row, col))) {
                    next_poses.push_back(make_pair(row, col));
                }
            }
        }
    }
    
    bool get_path(const vector<vector<char> >& board, const string& word, Path& path) {
        if (path.used_points.size() == word.size()) {
            return true;
        }
        
        // string flag = get_flag(path.cur_row, path.cur_col, path.used_points.size());
        // if (flags.end() != flags.find(flag)) {
        //     return false;
        // }
        
        vector<pair<int, int> > next_poses;
        get_next_poses(board, word, path, next_poses);
        int cur_row = path.cur_row, cur_col = path.cur_col;
        for(int i = 0; i < next_poses.size(); i ++) {
            long long int key = pack_key(next_poses[i].first, next_poses[i].second);
            path.used_points.insert(key);
            path.cur_row = next_poses[i].first, path.cur_col = next_poses[i].second;
            if (get_path(board, word, path)) {
                return true;
            }
            path.used_points.erase(key);
            path.cur_row = cur_row, path.cur_col = cur_col;
        }
        // flags.insert(flag);
        return false;
    }
    
    bool find_word(const vector<vector<char> >& board, const string& word) {
        if (word.size() <= 0) {
            return false;
        }
        
        initialize(board, word[0]);
        // cout << paths.size() << endl;
        for(int i = 0; i < paths.size(); i ++) {
            if (get_path(board, word, paths[i])) {
                return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> >& board, string word) {
        return find_word(board, word);
    }
};





