class Solution {
public:
	bool isValid(const string& s) {
		stack<char> ss;
		for(int i = 0; i < s.size(); i ++) {
			if ('(' == s[i]) {
				ss.push(s[i]);
			} else if ('[' == s[i]) {
				ss.push(s[i]);
			} else if ('{' == s[i]) {
				ss.push(s[i]);
			} else if (')' == s[i]) {
				if (ss.size() > 0 && '(' == ss.top()) {
					ss.pop();
				} else {
					return false;
				}
			} else if (']' == s[i]) {
				if (ss.size() > 0 && '[' == ss.top()) {
					ss.pop();
				} else {
					return false;
				}
			} else if ('}' == s[i]) {
				if (ss.size() > 0 && '{' == ss.top()) {
					ss.pop();
				} else {
					return false;
				}
			}
		}
		return ss.size() == 0;
	}
};
