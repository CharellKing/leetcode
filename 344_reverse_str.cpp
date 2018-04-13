class Solution {
public:
    string reverseString(string& s) {
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            char tmp = s[begin] ^ s[end];
            s[begin] = tmp ^ s[begin];
            s[end] = tmp ^ s[end];
            begin ++;
            end --;
        }
        return s;
    }
};
