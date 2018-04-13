class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unordered_nums;
        for(int i = 0; i < nums.size(); i ++) {
            if (unordered_nums.find(nums[i]) == unordered_nums.end()) {
                unordered_nums.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
