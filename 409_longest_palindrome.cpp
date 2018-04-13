class Solution {
public:
    int longestPalindrome(string s) {
        int chs[256];
        memset(chs, 0, 256 * sizeof(int));
        for(int i = 0; i < s.size(); i ++) {
        	chs[s[i]] ++;
        }

        int len = 0;
        for(int i = 0; i < 256; i ++) {
        	len += (chs[i] >> 1);
        }

        len <<= 1;
        if (s.size() > len) {
        	 len ++;
        }
        return len;
    }
};