class Solution {
public:
    void combine(const map<int, int>& num_count, map<int, int>::iterator& iter, int target, vector<vector<int>>& rets, vector<int>& ret) {
        if (0 == target) {
            if (ret.size() > 0) {
                rets.push_back(ret);
            }
            return;
        }
        
        if (iter == num_count.end()) {
            return;
        }
        
        if (target < iter->first) {
            return;
        }
        
        int count = target / iter->first;
        count = count > iter->second ? iter->second : count;
        for(int i = 0; i <= count; i ++) {
            for(int j = 0; j < i; j ++) {
                ret.push_back(iter->first);
            }
            map<int, int>::iterator tmp_iter = iter;
            tmp_iter++;
            combine(num_count, tmp_iter, target - i * iter->first, rets, ret);
            for(int j = 0; j < i; j ++) {
                ret.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> num_count;
        for(int i = 0; i < candidates.size(); i ++) {
            map<int, int>::iterator iter = num_count.insert(make_pair(candidates[i], 0)).first;
            iter->second ++;
        }
        
        vector<vector<int>> rets;
        vector<int> ret;
        map<int, int>::iterator iter = num_count.begin();
        combine(num_count, iter, target, rets, ret);
        return rets;
    }
};