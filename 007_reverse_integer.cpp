class Solution {
public:
	int reverse(int x) {
		long long int num = x;
		long long int sum = 0;
		int sign = 1;
		if (x < 0) {
			num = -num;
			sign = -1;
		}

		while (num > 0) {
			sum = (sum * 10 + num % 10);
			num /= 10;
		}
		return sum > 0x7fffffff ? 0 : (sign * sum);
	};
};
