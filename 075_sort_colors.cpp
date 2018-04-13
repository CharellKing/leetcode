class Solution {
public:
    void sort_colors(vector<int>& nums, int target) {
        int big_total = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] > target) {
                big_total ++;
            } else if (nums[i] == target) {
                if (big_total > 0) {
                    swap(nums[i], nums[i - big_total]);
                }
            }
        }
    }
    
    void sortColors(vector<int>& nums) {
       sort_colors(nums, 0);
       sort_colors(nums, 1);
    }
};
