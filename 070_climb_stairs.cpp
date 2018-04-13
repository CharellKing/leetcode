class Solution {
public:
    int climbStairs(int n) {
    	if（n <= 0) {
    		return 0;
    	} else if (n == 1) {
    		return 1;
    	} else if (n == 2) {
    		return 2;
    	}
    		
    	int first = 1, second = 2;
    	for(int i = 3; i <= n; i ++) {
    		int third = first + second;
    		first = second;
    		second = third;
    	}
    	return second
    }
};