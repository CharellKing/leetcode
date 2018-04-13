class Solution {
public:
	string convert(const string& s, int numRows) {
		if (s.size() <= 1 || numRows <= 1 || numRows >= s.size()) {
			return s;
		}

		string ret;
		int rows[2] = {0, numRows - 1};
		bool dest_direction = true;		
		int begin = 0;
		for(int row = rows[0]; row <= rows[1]; row ++) {
			int k = begin;
			dest_direction = true;			
			while (k < s.size()) {
				ret.push_back(s[k]);
				if (rows[dest_direction] == row) {
					dest_direction = !dest_direction;
				}
				k += abs(rows[dest_direction] - row) * 2;
				dest_direction = !dest_direction;
			}
			begin += 1;
		}
		return ret;
	}
};
