class Solution {
public:
	int romanToInt(const string& s) {
		int sum = 0;
		for(int i = 0; i < s.size(); i ++) {
			switch (s[i]) {
			case 'I':
				if (i + 1 < s.size() && s[i + 1] != 'I') {
					sum -= 1;
				} else {
					sum += 1;
				}
				break;
			case 'V':
				sum += 5;
				break;
			case 'X':
				if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C' || s[i + 1] == 'D' || s[i + 1] == 'M')) {
					sum -= 10;
				} else {
					sum += 10;
				}
				break;
			case 'L':
				sum += 50;
				break;
			case 'C':
				if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
					sum -= 100;
				} else {
					sum += 100;
				}
				break;
			case 'D':
				sum += 500;
				break;
			case 'M':
				sum += 1000;
				break;
			default:
				break;
			}		
		} 
		return sum;
	}
};
