class Solution {
public:
    bool is_reverse_sort(const vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }
        
        int i = 1;
        while (i < nums.size() && nums[i] <= nums[i - 1]) {
            i ++;
        }
        return i == nums.size();
    }
    
    void reverse_sort(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i ++;
            j --;
        }
    }
    
    template <typename T>
    struct Cmp {
        bool operator()(const T& a, const T& b) {
            return a > b;
        }
    };
    
    void nextPermutation(vector<int>& nums) {
        if (is_reverse_sort(nums)) {
            reverse_sort(nums);
            return ;
        }
        
        vector<int> copy_nums = nums;
        vector<int>::reverse_iterator cur_iter = nums.rbegin(), next_iter = nums.rbegin();
        next_iter ++;
        while (*next_iter >= *cur_iter) {
            cur_iter ++;
            next_iter ++;
        }
        
        vector<int>::iterator iter = next_iter.base();
        while (iter != nums.end() && *iter > *next_iter) {
            iter ++;
        }
        
        swap(*next_iter, *prev(iter));
        sort(next_iter.base(), nums.end());
    }
};
