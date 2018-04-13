class Solution {
public:
	bool is_vowel(char ch) {
		ch = tolower(ch);
		return 'a' ==  ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch;
	}

	void swap(char& a, char& b) {
		char c = a;
		a = b;
		b = c;
	}

	string reverseVowels(string s) {
		int begin = 0, end = s.size() - 1;
		while (begin < end) {
			while (!is_vowel(s[begin])) {
				begin ++;
			}

			while (!is_vowel(s[end])) {
				end --;
			}

			if (begin < end) {
				swap(s[begin], s[end]);
			}

			begin ++;
			end --;
		}
		return s;
	}
};
