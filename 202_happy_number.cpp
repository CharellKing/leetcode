class Solution {
public:
    int next_number(int n) {
        int num = 0;
        while (n > 0) {
            int digit = n % 10;
            num += digit * digit;
            n /= 10;
        }
        return num;
    }
    
    bool isHappy(int n) {
        unordered_set<int> nums;
        while (n != 1) {
            if (nums.find(n) != nums.end()) {
                return false;
            }
            nums.insert(n);
            n = next_number(n);
        }
        return true;
    }
};