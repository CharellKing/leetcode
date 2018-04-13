class Solution {
public:
    string next_number(const string& num) {
        stringstream ss;
        string new_num;
        int i = 0;
        while (i < num.size()) {
            int count = 1;
            while (i + 1 < num.size() && num[i] == num[i + 1]) {
                count ++;
                i ++;
            }
            ss.str("");
            ss << count;
            new_num += ss.str();
            new_num.push_back(num[i]);
            i ++;
        }
        return new_num;
    }
    string countAndSay(int n) {
        string num = "1";
        for(int i = 1; i < n; i ++) {
            num = next_number(num);
        }
        return num;
    }
};
