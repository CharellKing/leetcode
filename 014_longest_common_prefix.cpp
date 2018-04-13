class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int j = 0;
        while(true) {
            char ch = '\0';
            int i = 0;
            while(i < strs.size()) {
                if (j < strs[i].size()) {
                    if ('\0' == ch) {
                        ch = strs[i][j];
                    } else if (ch != strs[i][j]) {
                        break;
                    }    
                } else {
                    break;
                }
                i ++;
            }
            if (i >= strs.size() && '\0' != ch) {
                prefix.push_back(ch);
                j ++;
            } else {
                break;
            }
        }
        return prefix;
    }
};
