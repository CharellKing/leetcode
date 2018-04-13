class Solution {
public:
    int myAtoi(string str) {
        long long int sum = 0;
        int i = 0;
        int sign = 1;
        while (' ' == str[i]) {
            i ++;
        }

        if ('-' == str[i] || '+' == str[i]) {
            if ('-' == str[i]) {
                sign = -1;
            }
            i ++;
        }
        for(; i < str.size() &&  str[i] >= '0' && str[i] <= '9'; i ++) {
            sum = sum * 10 + str[i] - '0';
            if (sum * sign > 2147483647) {
                sum = 2147483647;
                break;
            } else if (sum * sign < -2147483648) {
                sum = -2147483648;
                break;
            }
        }
        return sum * sign;        
    }
};
