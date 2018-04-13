class Solution {
public:
    int closest(const vector<int>& nums, int begin, int end, int target) {
        if (nums[begin] >= target) {
            return nums[begin];
        } 
        
        if (nums[end] <= target) {
            return nums[end];
        }
        
        while (begin <= end) {
            if (begin + 1 >= end) {
                if (target - nums[begin] >= target - nums[end]) {
                    return nums[end];
                } else {
                    return nums[begin];
                }
            }
            
            int mid = (begin + end) >> 1;
            if (target == nums[mid]) {
                return nums[mid];
            } else if (target > nums[mid]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int distance = INT_MAX, closest_sum = 0;
        for(int i = 0; i < nums.size() - 2; i ++) {
            if (0 != i && nums[i] == nums[i - 1]) {
                continue;
            }
            
            
            if (nums[i] + nums[i + 1] + nums[i + 2] >= target) {
                if (nums[i] + nums[i + 1] + nums[i + 2] - target <= distance) {
                    closest_sum = nums[i] + nums[i + 1] + nums[i + 2];
                }
                break;
            }
            
            if (nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] <= target) {
                if (target - nums[nums.size() - 1] - nums[nums.size() - 2] - nums[nums.size() - 3] <= distance) {
                    closest_sum = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
                }
                break;
            }
            
            for(int j = i + 1; j < nums.size() - 1; j ++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                int remain = target - nums[i] - nums[j];
                int number = closest(nums, j + 1, nums.size() - 1, remain);
                if (abs(remain - number) < distance) {
                    closest_sum = nums[i] + nums[j] + number;
                    distance = abs(remain - number);
                }
            }
        }
        return closest_sum;
    }
};
