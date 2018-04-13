class Solution {
public:
	string longestPalindrome(const string& s) {
		if (s.size() <= 1) {
			return "";
		}

		vector<unordered_set<int>> chs = vector<vector<int>>(256, unordered_set<int>());
		unordered_set<double> mids;		
		string max_palindrome;		
		for(int i = 0; i < s.size(); i ++) {
			chs[s[i]].insert(i);
		}
		
		for(int i = 0; i < 256; i ++) {

		}
	}
};
