class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (1 == num) return true;
        
        int rem2 = num % 2, rem3 = num % 3, rem5 = num % 5;
        while (0 == rem2 || 0 == rem3 || 0 == rem5) {
            if (0 == rem2) num /= 2;
            if (0 == rem3) num /= 3;
            if (0 == rem5) num /= 5;
            
            rem2 = num % 2;
            rem3 = num % 3;
            rem5 = num % 5;
        }
        return 1 == num;
    }
};
