class Solution {
public:
    void combine(const vector<int>& nums, unordered_map<int, int>& num_count, vector<vector<int>>& rets, vector<int>& ret) {
        if (ret.size() == nums.size()) {
            rets.push_back(ret);
            return;
        }
        
        for(unordered_map<int, int>::iterator iter = num_count.begin(); num_count.end() != iter; iter ++) {
            if (iter->second > 0) {
                iter->second --;
                ret.push_back(iter->first);
                combine(nums, num_count, rets, ret);
                ret.pop_back();
                iter->second ++;
            }
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> num_count;
        for(int i = 0; i < nums.size(); i ++) {
            unordered_map<int, int>::iterator iter= num_count.insert(make_pair(nums[i], 0)).first;
            iter->second ++;
        }
        
        vector<vector<int>> rets;
        vector<int> ret;
        combine(nums, num_count, rets, ret);
        return rets;
    }
};