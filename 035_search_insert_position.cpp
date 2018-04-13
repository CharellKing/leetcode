class Solution {
public:
    int pos(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1, mid = (begin + end) >> 1;
        while (begin < end) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                if (nums[mid - 1] < target) {
                    return mid;
                } else if (nums[mid - 1] == target) {
                    return mid - 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (nums[mid + 1] > target) {
                    return mid + 1;
                } else if (nums[mid + 1] == target) {
                    return mid + 1;
                } else {
                    begin = mid + 1;
                }
            }
            mid = (begin + end) >> 1;
        }
        return 0;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() <= 0) {
            return 0;
        } 
        
        if (target < nums[0]) {
            return 0;
        }
        
        if (target > nums[nums.size() - 1]) {
            return nums.size();
        }
        return pos(nums, target);
    }
};
