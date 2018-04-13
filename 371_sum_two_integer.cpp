#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (a) {
            int x = (a ^ b);
            a = (a & b) << 1;
            b = x;
        }
        return b;
    }
};
/*
int main() {
    Solution().getSum(10, 8);
    return 0;
}*/
