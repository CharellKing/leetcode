class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() <= 0) {
            return num2;
        }
        
        if (num2.size() <= 0) {
            return num1;
        }
        
        int i = num1.size() - 1, j = num2.size() - 1;
        string ret;
        int remain = 0;
        while (i >= 0 && j >= 0) {
            int k = remain + num1[i] - '0' + num2[j] - '0';
            if (k >= 10) {
                remain = 1;
                k -= 10;
            } else {
                remain = 0;
            }
            ret.push_back(k + '0');
            i --;
            j --;
        }
        
        while (i >= 0) {
            int k = remain + num1[i] - '0';
            if (k >= 10) {
                remain = 1;
                k -= 10;
            } else {
                remain = 0;
            }
            ret.push_back(k + '0');
            i --;
        }
        
        while (j >= 0) {
            int k = remain + num2[j] - '0';
            if (k >= 10) {
                remain = 1;
                k -= 10;
            } else {
                remain = 0;
            }
            ret.push_back(k + '0');
            j --;
        }
        
        if (1 == remain) {
            ret.push_back('1');
        }
        return string(ret.rbegin(), ret.rend());
    }
};
