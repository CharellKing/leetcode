class Solution {
public:
    string convertToTitle(int n) {
        list<char> res;
        do {
            n --;
            res.push_front('A' + n % 26);
            n = n / 26;
        } while (n > 0);
        return string(res.begin(), res.end());     
    }
};
