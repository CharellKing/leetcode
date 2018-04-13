class Solution {
public:
    void split(const string& num, string& left, string& right) {
        int mid = num.size() >> 1;
        left = num.substr(0, mid);
        right = num.substr(mid, num.size() - mid);
    }
    
    string plus(const string& val1, const string& val2) {
        int i = val1.size() - 1, j = val2.size() - 1, remain = 0;
        list<char> ret;
        while(i >= 0 && j >= 0) {
            int k = val1[i] - '0' + val2[j] - '0' + remain;
            if (k >= 10) {
                k -= 10;
                remain = 1;
            } else {
                remain = 0;
            }
            ret.push_back(k + '0');
            i --;
            j --;
        }
        
        while(i >= 0) {
            int k = val1[i] - '0' + remain;
            if (k >= 10) {
                k -= 10;
                remain = 1;
            } else {
                remain = 0;
            }
            ret.push_back(k + '0');
            i --;
        }
        
        while(j >= 0) {
            int k = val2[j] - '0' + remain;
            if (k >= 10) {
                k -= 10;
                remain = 1;
            } else {
                remain = 0;
            }
            ret.push_back(k + '0');
            j --;
        }
        
        if (remain > 0) {
            ret.push_back('0' + remain);
        }
        
        return string(ret.rbegin(), ret.rend());
    }
    
    string& carry(string& val, int n) {
        return val.append(n, '0');    
    }
    
    void strip(string& num) {
        int space_count = 0;
        for(int i = 0; i < num.size(); i ++) {
            if (num[i] == ' ') {
                space_count ++;
            } else {
                num[i - space_count] = num[i];
            }
        }
        
        for(int i = 0; i < space_count; i ++) {
            num.pop_back();
        }
    }
    
    bool is_zero(string& num) {
        for(int i = 0; i < num.size(); i ++) {
            if (num[i] != '0') {
                return false;
            }
        }
        return true;
    }
    
    string multiply_deduce(string& num1, string& num2) {
        if (num1.size() == 1 && 1 == num2.size()) {
            stringstream ss;
            ss << (num1[0] - '0') * (num2[0] - '0');
            return ss.str();
        }
        
        if (is_zero(num1) || is_zero(num2)) {
            return "0";    
        }
        
        string sum = "0", val = "";
        string left1, right1, left2, right2;
        split(num1, left1, right1);
        split(num2, left2, right2);
        
        if (right1.size() > 0 && right2.size() > 0) {
            val = multiply(right1, right2);
            sum = val;
        } 
        
        if (left1.size() > 0 && right2.size() > 0) {
            val = multiply(left1, right2);
            val = carry(val, right1.size());
            sum = plus(sum, val);
        }
        
        if (right1.size() > 0 && left2.size() > 0) {
            val = multiply(right1, left2);
            val = carry(val, right2.size());
            sum = plus(sum, val);
        }
        
        if (left1.size() > 0 && left2.size() > 0) {
            val = multiply(left1, left2);
            val = carry(val, right1.size() + right2.size());
            sum = plus(sum, val);
        }
        return sum;
    }
    
    string multiply(string& num1, string& num2) {
        strip(num1);
        strip(num2);
        return multiply_deduce(num1, num2);
    }
    
};