class Solution {
public:
	void reset_chs(const string& s, int* chs, int from, int end) {
		for(int i = from; i <= end; i ++) {
			chs[s[i]] = -1;
		}
	}

	void initialize(int* chs) {
		for(int i = 0; i < 256; i ++) {
			chs[i] = -1;
		}
	}

	int lengthOfLongestSubstring(const string& s) {
		int chs[256] = {-1};
		int max_length = 0;
		int sub_begin = 0;
		
		initialize(chs);
		for(int i = 0; i < s.size(); i ++) {
			if (chs[s[i]] == -1) {
				chs[s[i]] = i;
			} else {
				int len = i - sub_begin;
				if (len > max_length) {
					max_length = len;
				}
				int tmp = sub_begin;
				sub_begin = chs[s[i]] + 1;
				reset_chs(s, chs, tmp, chs[s[i]]);
				chs[s[i]] = i;		
			}
		}

		int len = s.size() - sub_begin;
		if (len > max_length) {
			max_length = len;
		}
		return max_length;        
	}
};
