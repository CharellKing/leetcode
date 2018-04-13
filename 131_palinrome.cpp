class Solution {
public:
    bool is_palindrome(const string& s, int from, int to) {
        while (from < to) {
            if (s[from] != s[to]) {
                return false;
            }
            from ++;
            to --;
        }
        return true;
    }
    
    vector<vector<string>> partition(const string& s) {
        vector<vector<int>> one_layer, two_layer;
        vector<vector<int>> &cur_layer = one_layer, &next_layer = two_layer;
        cur_layer.push_back(vector<int>(1, 0));
        vector<vector<int>> ret;
        while (cur_layer.size() > 0) {
            for(int i = 0; i < cur_layer.size(); i ++) {
                if (cur_layer[i].back() == s.size()) {
                    cur_layer[i].pop_back();
                    ret.push_back(cur_layer[i]);
                } else {
                    for(int j = cur_layer[i].back(); j < s.size(); j ++) {
                        if (is_palindrome(s, cur_layer[i].back(), j)) {
                            next_layer.push_back(cur_layer[i]);
                            next_layer.back().push_back(j);
                            next_layer.back().push_back(j + 1);
                        }  
                    }
                }    
            }
            swap(cur_layer, next_layer);
            next_layer.clear();
        }
        
        vector<vector<string>> strs;
        for(int i = 0; i < ret.size(); i ++) {
            strs.push_back(vector<string>());
            for(int j = 0; j < ret[i].size(); ) {
                strs.back().push_back(s.substr(ret[i][j], ret[i][j + 1] - ret[i][j] + 1));
                j += 2;
            }
        }
        
        return strs;
    }
};
