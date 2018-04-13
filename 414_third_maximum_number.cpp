class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maximums[3] = {INT_MIN, INT_MIN, INT_MIN};
        unordered_set<int> unordered_nums;
        for(int i = 0; i < nums.size(); i ++) {
            if (unordered_nums.size() < 3) {
                unordered_nums.insert(nums[i]);
            }
            for(int j = 0; j < 3; j ++) {
                if (nums[i] > maximums[j]) {
                    swap(nums[i], maximums[j]);
                } else if (nums[i] == maximums[j]) {
                    break;
                }
            }
        }
        
        if (unordered_nums.size() <= 0) {
            return 0;
        }
        
        if (unordered_nums.size() < 3) {
            return maximums[0];
        }
        
        return maximums[2];
    }
};
