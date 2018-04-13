// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1)) {
            return 1;
        }
        
        if (false == isBadVersion(n)) {
            return 0;
        }
        
        long long int begin = 1, end = n, mid = (1 + n) >> 1;
        while (begin <= end) {
            if (isBadVersion(mid)) {
                if (false == isBadVersion(mid - 1)) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else {
                begin = mid + 1;
            }
            mid = (begin + end) >> 1;
        }
        return 0;
    }
};
