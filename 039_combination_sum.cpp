class Solution {
public:
    void combine(const set<int>& nums, vector<vector<int>>& rets, vector<int>& ret, set<int>::iterator& iter, int target) {
        if (0 == target) {
            if (ret.size() > 0) {
                rets.push_back(ret);
            }
            return;
        }
        
        if (iter == nums.end()) {
            return;
        }
        
        if (*iter > target) {
            return;
        }
        
        int n = target / *iter;
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j < i; j ++) {
                ret.push_back(*iter);
            }
            set<int>::iterator tmp_iter = iter;
            tmp_iter ++;
            combine(nums, rets, ret, tmp_iter, target - (*iter) * i);
            for(int j = 0; j < i; j ++) {
                ret.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (target <= 0) {
            return vector<vector<int>>();
        }
        
        set<int> nums;
        for(int i = 0; i < candidates.size(); i ++) {
            nums.insert(candidates[i]);
        }
        
        vector<vector<int>> rets;
        vector<int> ret;
        set<int>::iterator iter = nums.begin();
        combine(nums, rets, ret, iter, target);
        return rets;
    }
};