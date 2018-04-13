class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        for(int i = 0; i < nums.size(); i ++) {
            sums.push_back(sums.back() + nums[i]);
        }
    }

    int to_sum(int i) {
        int val = 0;
        if (i < 0) {
            val = sums[0];
        } else if (i >= sums.size()) {
            val = sums.back();
        } else {
            val = sums[i + 1];
        }
        return val;
    }
    
    int sumRange(int i, int j) {
        return to_sum(j) - to_sum(i- 1);    
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
