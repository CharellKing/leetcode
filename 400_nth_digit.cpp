class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) {
            return n;
        }
        
        long long int digit_count = 1, number_count = 9, sum = 9, prior_sum = 9;
        while (sum < n) {
            digit_count ++;
            number_count *= 10;
            prior_sum = sum;
            sum += digit_count * number_count;
        }
        
        long long int remain_digits = n - prior_sum;
        long long int remain_numbers = (remain_digits - 1) / digit_count;
        long long int begin_num = pow(10, digit_count - 1);
        long long int number = begin_num + remain_numbers;
        long long int number_digit = remain_digits % digit_count;
        //cout << number << " " << number_digit <<  " " << remain_numbers << endl;
        if (0 == number_digit) {
            number_digit = 1;
        } else {
            number_digit = digit_count - number_digit + 1; 
        }
        
        for(int i = 1; i < number_digit; i ++) {
            number /= 10;
        }
        return number % 10;
    }
};
