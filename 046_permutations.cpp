class Solution {
public:
    void combine(const vector<int>& nums, vector<vector<int>>& rets, vector<int>& ret, unordered_set<int>& existed_nums) {
        if (ret.size() == nums.size()) {
            rets.push_back(ret);
            return ;
        }
        
        for(int i = 0; i < nums.size(); i ++) {
            if (existed_nums.end() == existed_nums.find(nums[i])) {
                existed_nums.insert(nums[i]);
                ret.push_back(nums[i]);
                combine(nums, rets, ret, existed_nums);
                ret.pop_back();
                existed_nums.erase(nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> rets;
        vector<int> ret;
        unordered_set<int> existed_nums;
        combine(nums, rets, ret, existed_nums);
        return rets;
    }
};