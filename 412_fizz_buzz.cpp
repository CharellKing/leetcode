class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int three = 1, five = 1;
        vector<string> ret;
        stringstream ss;
        for(int i = 1; i <= n; i ++) {
            if (3 == three && 5 == five) {
                ret.push_back("FizzBuzz");
                three = 1;
                five = 1;
            } else if (3 == three) {
                ret.push_back("Fizz");
                three = 1;
                five ++;
            } else if (5 == five) {
                ret.push_back("Buzz");
                five = 1;
                three ++;
            } else {
                ss << i;
                ret.push_back(ss.str());
                ss.str("");
                three ++;
                five ++;
            }
        }
        return ret;
    }
};
