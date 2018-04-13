class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
    	int sum = 0, rotate_sum = 0, max = 0;
        for(int i = 0; i < A.size(); i ++) {
        	sum += A[i];
        	rotate_sum += i * A[i];
        }

        max = rotate_sum;
        for(int i = 1; i < A.size(); i ++) {
        	rotate_sum = rotate_sum + sum - (A.size()) * A[A.size() - i];
        	if (max < rotate_sum) {
        		max = rotate_sum;
        	}
        }
        return max;
    }
};