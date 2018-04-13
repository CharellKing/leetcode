class Solution {
public:
    int get_max_product(const vector<int>& nums, int begin, int end, const vector<int>& negtive_spliters) {
        if (begin > end) {
            return INT_MIN;
        }
        
        if (begin == end) {
            return nums[begin];
        }
        
        int count = 0;
        for(int i = 0; i < negtive_spliters.size(); i ++) {
            if (negtive_spliters[i] >= begin && negtive_spliters[i] <= end) {
                count ++;
            }
            
            if (negtive_spliters[i] >= end) {
                break;
            }
        }
        
        int ret = 1;
        if ((count & 1) == 0) {
            for(int i = begin; i <= end; i ++) {
                ret *= nums[i];
            }
        } else {
            int val = 1;
            int i = begin;
            int left_val1 = INT_MIN, left_val2 = INT_MIN;
            bool has_val = false;
            while (nums[i] > 0) {
                val *= nums[i];
                i ++;
                has_val = true;
            }
            
            if (has_val) {
                left_val1 = val;    
            }
            
            i ++;
            val = 1;
            has_val = false;
            while (i <= end) {
                val *= nums[i];
                i ++;
                has_val = true;
            }
            
            if (has_val) {
                left_val2 = val;
            }
            
            i = end;
            int right_val1 = INT_MIN, right_val2 = INT_MIN;
            val = 1;
            has_val = false;
            while (nums[i] > 0) {
                val *= nums[i];
                i --;
                has_val = true;
            }
            
            if (has_val) {
                right_val1 = val;
            }
            i --;
            
            val = 1;
            has_val = false;
            while (i >= begin) {
                val *= nums[i];
                i --;
                has_val = true;
            }
            
            if (has_val) {
                right_val2 = val;    
            }
            
            ret = left_val1;
            if (ret < left_val2) {
                ret = left_val2;
            }
            
            if (ret < right_val1) {
                ret = right_val1;
            } 
            
            if (ret < right_val2) {
                ret = right_val2;
            }
        }
        return ret;
    }
    
    int maxProduct(vector<int>& nums) {
        if (nums.size() <= 0) {
            return INT_MIN;
        }
        vector<int> zero_spliters;
        vector<int> negtive_spliters;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                zero_spliters.push_back(i);
            } else if (nums[i] < 0) {
                negtive_spliters.push_back(i);
            }
        }
        
        if (zero_spliters.size() + negtive_spliters.size() == nums.size()) {
            if (negtive_spliters.size() == 1) {
                if (zero_spliters.size() > 0) {
                    return 0;
                } else {
                    return nums[0];
                }
            } else if (negtive_spliters.size() == 0) {
                return 0;
            }
        }
        
        int max = INT_MIN;
        zero_spliters.push_back(nums.size());

        int begin = 0;
            
        for(int i = 0; i < zero_spliters.size(); i ++) {
            int ret = get_max_product(nums, begin, zero_spliters[i] - 1, negtive_spliters);
            if (max < ret) {
                max = ret;
            }
            begin = zero_spliters[i] + 1;
        }
        
        if (max < 0 && zero_spliters.size() > 0) {
            max = 0;
        }
        return max;
    }
};
