class Solution {
public:
    void combine_deduce(int n, int from, int k, vector<vector<int>>& rets, vector<int>& ret) {
        if (0 == k) {
            rets.push_back(ret);
            return;
        }
        
        for(int i = from; i <= n - k + 1; i ++) {
            ret.push_back(i);
            combine_deduce(n, i + 1, k - 1, rets, ret);
            ret.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        if (k > n) {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> rets;
        vector<int> ret;
        combine_deduce(n, 1, k, rets, ret);
        return rets;
    }
};
