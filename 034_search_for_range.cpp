class Solution {
public:
    int left(const vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, mid = (begin + end) >> 1;
        while (begin <= end) {
            if (nums[mid] == target) {
                if (mid <= 0 || nums[mid - 1] != target) {
                    return mid;
                }
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (begin + end) >> 1;
        }
        return -1;
    }
    
    int right(const vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, mid = (begin + end) >> 1;
        while (begin <= end) {
            if (nums[mid] == target) {
                if (mid >= nums.size() - 1 || nums[mid + 1] != target) {
                    return mid;
                }
                begin = mid + 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (begin + end) >> 1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() <= 0) {
            return vector<int>({-1, -1});
        }
        
        int left_range = left(nums, target);
        int right_range = -1;
        if (left_range >= 0) {
            right_range = right(nums, target);
        }
        
        return vector<int>({left_range, right_range});
    }
};
