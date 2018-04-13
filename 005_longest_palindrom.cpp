class Solution {
public:
	void get_palindrome(const string& s, double mid, int& from, int& to) {
		if ((int)mid == mid) {
			from = mid - 1, to = mid + 1;
		} else {
			from = int(mid - 0.5), to = int(mid + 0.5);
		}

		while (from >= 0 && to < s.size() && s[from] == s[to]) {
			from -= 1;
			to += 1;
		}
		from += 1;
		to -= 1;		
	}

	string longestPalindrome(const string& s) {
		if (s.size() <= 1) {
			return s;
		}
		
		double mid = (0 + s.size() - 1) * 1.0 / 2;
		double left = mid, right = mid;
		int from = 0, to = 0;
		string longest_str;
		
		while (left > 0.0 && right < s.size()) {
			if (int((1 + left) * 2) <= longest_str.size()) {
				break;
			}
			
			if (left == right) {
				get_palindrome(s, left, from, to);	
				if (to - from + 1 > longest_str.size()) {
					longest_str = s.substr(from, to - from + 1);
				}				
			} else {
				get_palindrome(s, left, from, to);
				if (to - from + 1 > longest_str.size()) {
					longest_str = s.substr(from, to - from + 1);
				}
				get_palindrome(s, right, from, to);
				if (to - from + 1 > longest_str.size()) {
					longest_str = s.substr(from, to - from + 1);
				}
			}

			left -= 0.5;
			right += 0.5;
		}
		return longest_str;		
	}
};
