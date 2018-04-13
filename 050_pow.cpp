class Solution {
public:
    double myPow(double x, int n) {
        if (0 == x) {
            return 0;
        }
        
        if (0 == n) {
            return 1;
        }
        
        if (1 == x) {
            return 1;
        }
        
        long long int m = n > 0 ? n : -(long long int)(n);
        double ret = 1;
        unordered_map<int, double> nums;
        nums.insert(make_pair(1, x));
        long long int k = 1;
        while (k <= m) {
            nums.insert(make_pair(k << 1, nums[k] * nums[k]));
            k <<= 1;
        }
        
        while (m > 0) {
            if (k <= m) {
                ret *= nums[k];
                m -= k;
            }
            k >>= 1;
        }
        return n >= 0 ? ret : (1.0 / ret);
    }
};