class Solution {
public:
	void combine(unordered_map<int, int>::const_iterator cur, unordered_map<int, int>::const_iterator end, vector<int>& ret, vector<vector<int>>& rets) {
		if (cur == end) {
			rets.push_back(ret);
			return;
		}

		for(int i = 0; i <= cur->second; i ++) {
			for(int j = 0; j < i; j ++) {
				ret.push_back(cur->first);
			}
			unordered_map<int, int>::const_iterator tmp = cur;
			tmp ++;
			combine(tmp, end, ret, rets);
			for(int j = 0; j < i; j ++) {
				ret.pop_back();
			}
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rets;
        vector<int> ret;
        
        unordered_map<int, int> num_count;
        for(int i = 0; i < nums.size(); i ++) {
        	unordered_map<int, int>::iterator iter = num_count.insert(make_pair(nums[i], 0)).first;
        	iter->second ++;
        }
        combine(num_count.begin(), num_count.end(), ret, rets);
        return rets;
    }
};