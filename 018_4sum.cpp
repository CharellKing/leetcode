class Solution {
public:
    bool is_existed(const vector<int>& nums, int from, int len, int target) {
        int min_val = 0, max_val = 0;
        for(int i = 0; i < len; i ++) {
            min_val += nums[from + i];
            max_val += nums[nums.size() - i - 1];
        }
        return target >= min_val && target <= max_val;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_count;
        vector<vector<int>> ret;
        
        if (nums.size() < 4) {
            return ret;
        }
        
        
        sort(nums.begin(), nums.end());
        int end = nums.size() - 1;
        if (nums[end] + nums[end - 1] + nums[end - 2] + nums[end - 3] < target) {
            return ret;
        }
        
        
        for(int i = 0; i < nums.size(); i ++) {
            unordered_map<int, int>::iterator iter = num_count.insert(make_pair(nums[i], 0)).first;
            iter->second ++;
        }
        
        if (is_existed(nums, 0, 4, target)) {
            for(int i = 0; i < nums.size() - 3; i ++) {
                if ((0 == i || nums[i] != nums[i - 1])) {
                    num_count[nums[i]] --;
                    if (is_existed(nums, i + 1, 3, target - nums[i])) {
                        for(int j = i + 1; j < nums.size() - 2; j ++) {
                            if (j == i + 1 || nums[j] != nums[j - 1]) {
                                num_count[nums[j]] --;
                                if (is_existed(nums, j + 1, 2, target - nums[i] - nums[j])) {
                                    for(int k = j + 1; k < nums.size() - 1; k ++) {
                                        if (k == j + 1 || nums[k] != nums[k - 1]) {
                                            num_count[nums[k]] --;
                                            int remain = target -nums[i] - nums[j] - nums[k];
                                            if (remain >= nums[k]) {
                                                unordered_map<int, int>::iterator iter = num_count.find(remain);
                                                if (iter != num_count.end() && iter->second > 0) {
                                                    ret.push_back(vector<int>());
                                                    ret.back().push_back(nums[i]);
                                                    ret.back().push_back(nums[j]);
                                                    ret.back().push_back(nums[k]);
                                                    ret.back().push_back(remain);
                                                }
                                            }
                                            num_count[nums[k]] ++;
                                        }
                                    }
                                }
                                num_count[nums[j]] ++;
                            }
                        }        
                    }
                    num_count[nums[i]] ++;
                }
            }
        }
        return ret;
    }
};
