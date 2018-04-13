class Solution {
public:
    string intToRoman(int num) {
        string ret;
        string thousands[5] = {"", "M", "MM", "MMM"};
        string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        string* decimals[4] = {thousands, hundreds, tens, ones};
        int decimal_numbers[4] = {1000, 100, 10, 1};
        
        int i = 0;
        while (i < 4 && num > 0) {
            ret += (decimals[i][num / decimal_numbers[i]]);
            num %= decimal_numbers[i];
            i ++;
        }
        
        return ret;
    }
};
