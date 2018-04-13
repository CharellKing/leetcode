class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int move_steps = 0, i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            int k = nums[i];
            nums[i - move_steps] = nums[i];
            while (j < nums.size() && nums[j] == nums[i]) {
                nums[j - move_steps] = nums[j];
                j ++;
            }
            
            if (j - i > 2) {
                move_steps += j - i - 2;
            }
            i = j;
        }
        return nums.size() - move_steps;
    }
};
