class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums.size() == 2) {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        
        int first = nums[0];
        int second = nums[0] > nums[1] ? nums[0] : nums[1];
        int i = 2;
        while (i < nums.size()) {
            int third = nums[i] + first > second ? nums[i] + first : second;
            first = second;
            second = third;
            i ++;
        }
        return second;
    }
};
