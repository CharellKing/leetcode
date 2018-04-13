class Solution {
public:
    string remainPlusOne(const string& a, int i) {
        int count = 0;
        string res;
        char remain = '1';
        while (i >= 0) {
            count = 0;
            if (a[i] == '1') count ++;
            if (remain == '1') count ++;
            if (count == 0) {
                res.push_back('0');
                remain = '0';
            } else if (count == 1) {
                res.push_back('1');
                remain = '0';
            } else if (count == 2) {
                res.push_back('0');
                remain = '1';
            }
            i --;
        }
        if ('1' == remain) {
            res.push_back(remain);
        }
        return res;
    }
    
    string reverseRemain(const string& s, int j) {
        string res;
        while (j >= 0) {
            res.push_back(s[j]);
            j --;
        }
        return res;
    }
    
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        char remain = '0';
        string res;
        int count = 0;
        while (i >= 0 && j >= 0) {
            count = 0;
            if (a[i] == '1') count ++;
            if (b[j] == '1') count ++;
            if (remain == '1') count ++;
            
            if (count >= 2) {
                remain = '1';
            } else {
                remain = '0';
            }
            
            if (1 == count || 3 == count) {
                res.push_back('1');
            } else {
                res.push_back('0');
            }
            
            i --;
            j --;
        }
        
        if (remain == '0') {
            if (i >= 0) {
                res += reverseRemain(a, i);
            } else if (j >= 0) {
                res += reverseRemain(b, j);
            }
        } else {
            if (i >= 0) {
                res += remainPlusOne(a, i);
            } else if (j >= 0) {
                res += remainPlusOne(b, j); 
            } else {
                res.push_back(remain);
            }
        }
        
        if ("" == res) {
            res = "0";
        }
        return string(res.rbegin(), res.rend());
    }
