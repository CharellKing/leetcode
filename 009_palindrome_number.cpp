class Solution {
public:
	int get_max_decimal(int x) {
		int val = 1000000000;
		while (x / val <= 0) {
			val /= 10;
		}
		return val;
	}
    bool isPalindrome(int x) {
        if (x < 0) {
        	return false;
        }

        if (x < 10) {
        	return true;
        }

        int end = get_max_decimal(x);
        int begin = 1;

        while (end > begin) {
        	if (x / end % 10 != x / begin % 10) {
        		return false;
        	}
        	begin *= 10;
        	end /= 10;
        }
        return true;
    }
};
