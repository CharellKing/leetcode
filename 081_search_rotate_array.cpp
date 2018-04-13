class Solution {
public:
    bool find_target(const vector<int>& nums, int begin, int end, int target) {
        if (begin > end) {
            return false;
        }
        
        int mid = (begin + end) >> 1;
        if (nums[mid] == target) {
            return true;
        }
        
        if (nums[begin] < nums[end]) {
            if (nums[mid] > target) {
                if (true == find_target(nums, begin, mid - 1, target)) {
                    return true;
                }
            } else {
                if (true == find_target(nums, mid + 1, end, target)) {
                    return true;
                }
            }
        } else {
            if (true == find_target(nums, begin, mid - 1, target)) {
                return true;
            } else {
                if (true == find_target(nums, mid + 1, end, target)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        if (nums.size() <= 0) {
            return false;
        }
        return find_target(nums, 0, nums.size() - 1, target);
    }
};
