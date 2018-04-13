class Solution {
public:
    void swap_section(vector<int>& nums, int left, int right) {
        int n = right - left;
        for(int i = 0; i < n; i ++) {
            std::swap(nums[left + i], nums[right + i]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k > 0) {
            int left_from = 0, left_to = nums.size() - k - 1, right_from = nums.size() - k, right_to = nums.size() - 1;
            while (left_to < right_from && left_from <= left_to && right_from <= right_to) {
                int left_len = left_to - left_from + 1;
                int right_len = right_to - right_from + 1;
                if (left_len <= right_len) {
                    swap_section(nums, left_from, right_from);
                    left_from = right_from;
                    left_to = right_from + left_len - 1;
                    right_from = left_to + 1;
                } else if (left_len > right_len) {
                    swap_section(nums, left_from + left_len - right_len,  right_from);
                    left_to = left_from + left_len - right_len - 1;
                    right_from = left_from + left_len - right_len;
                    right_to = right_from + right_len - 1;
                }
            }
        }
    }
};
