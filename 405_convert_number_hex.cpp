class Solution {
public:
    string toHex(int num) {
        unsigned int k = (unsigned int) num;
        char chs[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        int fifth = 15;
        list<char> res;
        while (k) {
            int m = k & fifth;
            res.push_back(chs[m]);
            k >>= 4;
        }
        
        if (res.size() <= 0) {
            res.push_back('0');
        }
        return string(res.rbegin(), res.rend());
    }
};
