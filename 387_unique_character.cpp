class Solution {
public:
    int firstUniqChar(string s) {
        int chs[256];
        memset(chs, 0, sizeof(int) * 256);
        for(int i = 0; i < s.size(); i ++) {
            chs[s[i]] ++;
        }
        
        for(int i = 0; i < s.size(); i ++) {
            if (chs[s[i]] <= 1) {
                return i;
            }
        }
        return -1;
    }
};
