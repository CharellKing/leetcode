class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_counts = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if (0 == nums[i]) {
                zero_counts ++;
            } else {
                if (zero_counts > 0) {
                    swap(nums[i], nums[i - zero_counts]);
                }
            }
        }
    }
};
