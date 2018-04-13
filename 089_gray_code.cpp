class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) {
			return vector<int>({0});
		}

		vector<int> ret;
		ret.push_back(0);
		ret.push_back(1);
		
		for(int i = 2; i <= n; i ++) {
			for(int j = ret.size() - 1; j >= 0; j --) {
				ret.push_back(ret[j] | (1 << (i - 1)));
			}
		}
		return ret;
	}
};