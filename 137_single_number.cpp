class Solution {
public:
    int singleNumber(vector<int>& nums) {
        	int bits[32];
        	memset(bits, 0, sizeof(int) * 32);
	for(int i = 0; i < nums.size(); i ++) {
		for(int j = 0; j < 32; j ++) {
			if ((nums[i] >> j) & 1) {
				bits[j] ++;
				if (bits[j] >= 3) {
					bits[j] = 0;
				}
			}
		}
	}


	int ret = 0;
	for(int i = 0; i < 32; i ++) {
		ret |= (bits[i] << i);
	}
	return ret;
    }
};


