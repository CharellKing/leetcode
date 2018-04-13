class Solution {
public:
    void erase_num(vector<int>& nums, int index) {
        for(int i = index + 1; i < nums.size(); i ++) {
            nums[i - 1] = nums[i];
        }
    }
    
    string getPermutation(int n, int k) {
        if (k <= 0) {
            return "";
        }
        
        int count[10] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
        int i = 1;
        string ret;
        while (i <= n) {
            count[i] = i * count[i - 1];
            i ++;
        }
        
        vector<int> nums;
        for(int i = 0; i <= n; i ++) {
            nums.push_back(i);
        }
        
        for(int i = n; i >= 1 && k > 0; i --) {
            int j = k / count[i - 1];
            int m = k % count[i - 1];
            if (m > 0) {
                j ++;
            }
            ret.push_back(nums[j] + '0');
            erase_num(nums, j);
            k -= (j - 1) * count[i - 1];
        }
        return ret;
    }
};
