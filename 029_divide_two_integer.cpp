class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == dividend) {
            return 0;
        }
        
        if (0 == divisor) {
            return INT_MAX;
        }
        
        int sign = 1;
        if ((dividend < 0) ^ (divisor < 0)) {
            sign = -1;
        }
        
        long long int long_dividend = dividend, long_divisor = divisor;
        long_dividend = abs(long_dividend);
        long_divisor = abs(long_divisor);
        
        long long int ret = 0;
        while (long_dividend >= long_divisor) {
            long long int k = long_divisor;
            long long int bit = 1;
            while (k <= long_dividend) {
                k <<= 1;
                bit <<= 1;
            }
            ret += (bit >> 1);
            long_dividend -= (k >> 1);
        }
        
        ret = (sign < 0 ? -ret : ret);
        if (ret > INT_MAX || ret < INT_MIN) {
            return INT_MAX;
        }
        return ret;
    }
};
