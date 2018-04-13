class Solution {
public:
    char forward(const string& s, int& begin) {
        while (begin < s.size()) {
            if ((s[begin] >= 'a' && s[begin] <= 'z') || (s[begin] >= 'A' && s[begin] <= 'Z') || (s[begin] >= '0' && s[begin] <= '9')) {
                break;
            }
            begin ++;
        } 
        
        if (begin >= s.size()) {
            return '\0';
        }
        
        char ret = s[begin];
        if (s[begin] >= 'A' && s[begin] <= 'Z') {
            ret -= 'A';
            ret += 'a';
        }
        return ret;
    }
    
    char back(const string& s, int& end) {
        while (end >= 0) {
            if ((s[end] >= 'a' && s[end] <= 'z') || (s[end] >= 'A' && s[end] <= 'Z') ||  (s[end] >= '0' && s[end] <= '9')) {
                break;
            }
            end --;
        } 
        
        if (end < 0) {
            return '\0';
        }
        
        char ret = s[end];
        if (s[end] >= 'A' && s[end] <= 'Z') {
            ret -= 'A';
            ret += 'a';
        }
        return ret;
    }
    bool isPalindrome(const string& s) {
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            char left = forward(s, begin);
            char right = back(s, end);
            if (left && right) {
                if (left != right) {
                    return false;
                }
            }
            begin ++;
            end --;
        }
        return true;
    }
};