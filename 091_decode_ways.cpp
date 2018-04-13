class Solution {
public:
    bool is_valid(const string& s) {
        for(int i = 0; i < s.size(); i ++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            } else if (s[i] == '0') {
                if (i <= 0 || s[i - 1] <= '0' || s[i - 1] >= '3') {
                    return false;
                }
            }
        }
        return true;
    }
    
    int number(const string& s, int i) {
        return (s[i - 1] - '0') * 10 + (s[i] - '0');    
    }
    
    int numDecodings(string s) {
        if (s.size() <= 0 || is_valid(s) <= 0) {
            return 0;
        }
        
        int first = 1;
        if (s.size() <= 1) {
            return first;
        }
        
        int second = 0;
        int val = number(s, 1);
        if (s[1] >= '1') {
            second += 1;
        }
        if (val >= 10 && val <= 26) {
            second ++;
        }
        if (s.size() <= 2) {
            return second;
        }
        
        for(int i = 2; i < s.size(); i ++) {
            int sum = 0;
            if (s[i] >= '1') {
                sum += second;
            }
            
            val = number(s, i);
            if (val >= 10 && val <= 26) {
                sum += first;
            }
            first = second;
            second = sum;
        }
        return second;
    }
};
