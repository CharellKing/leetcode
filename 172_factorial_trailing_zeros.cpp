class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        long long int k = 5;
        while (k <= n) {
            sum += n / k;
            k *= 5;
        }
        return sum;
    }
};
