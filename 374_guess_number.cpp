// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int begin = 1, end = n, mid = (1 + n) >> 1;
        while (begin <= end) {
            int ret = guess(mid);
            if (0 == ret) {
                return mid;
            } else if (ret < 0) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
            
            mid = (begin + end) >> 1;
            
        }
        return 0;
    }
};
