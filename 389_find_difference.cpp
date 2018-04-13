class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_chs[256], t_chs[256];
        memset(s_chs, 0, 256 * sizeof(int));
        memset(t_chs, 0, 256 * sizeof(int));
        
        for(int i = 0; i < s.size(); i ++) {
            s_chs[s[i]] ++;
        }
        
        for(int j = 0; j < t.size(); j ++) {
            t_chs[t[j]] ++;
        }
        
        for(int i = 0; i < 256; i ++) {
            if (s_chs[i] != t_chs[i]) {
                return i;
            }
        }
        return -1;
    }
};
