class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int remain = 1;
        for(int i = digits.size() - 1; i >= 0; i --) {
            digits[i] += remain;
            if (digits[i] >= 10) {
                digits[i] = 0;
                remain = 1;
            } else {
                remain = 0;
                break;
            }
        }
        if (remain == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
