class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int prior_num = nums[0], count = 1, i = 1;
        while (i < nums.size()) {
            if (count > 0) {
                if (prior_num == nums[i]) {
                    count ++;
                } else {
                    count --;
                }
            } else {
                prior_num = nums[i];
                count = 1;
            }
            i ++;
        }
        return prior_num;
    }
};
