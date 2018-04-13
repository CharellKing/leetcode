class Solution {
public:
    int mySqrt(int x) {
        if (0 == x) return 0;
        if (1 == x) return 1;
        long long int y = x;
        long long int end = x >> 1;
        long long int begin = 0;     
        while (begin <= end) {
            long long int mid = (begin + end) >> 1;
            if (mid * mid > y) {
                end = mid - 1;
            } else if (mid * mid == y) {
                return mid;
            } else {
                if ((mid + 1) * (mid + 1) > y) {
                    return mid;
                } else {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};
