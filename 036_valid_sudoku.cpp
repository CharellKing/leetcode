class Solution {
public:
	bool horizon_is_valid(const vector<vector<char>>& board) {
		int row = board.size(), col = board[0].size();
		for(int i = 0; i < row; i ++) {
			int digit_is_existed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			for(int j = 0; j < col; j ++) {
				if (board[i][j] != '.') {
					if (digit_is_existed[board[i][j] - '0'] == 1) {
					    return false;
					} else {
						digit_is_existed[board[i][j] - '0'] = 1;
					}
				}
			}
		}
		return true;
	}

	bool vertical_is_valid(const vector<vector<char>>& board) {
		int row = board.size(), col = board[0].size();
		for(int i = 0; i < col; i ++) {
			char digit_is_existed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			for(int j = 0; j < row; j ++) {
				if (board[j][i] != '.') {
					if (digit_is_existed[board[j][i] - '0'] == 1) {
					    return false;
					} else {
						digit_is_existed[board[j][i] - '0'] = 1;
					}
				}
			}
		}
		return true;
	}

	bool nine_grid_is_valid(const vector<vector<char>>& board) {
		int increase_grid = 3, row = board.size(), col = board[0].size();
		for(int i = 0; i < row; i += increase_grid) {
			for(int j = 0; j < col; j += increase_grid) {
			    int origin_row = i, origin_col = j;
				int digit_is_existed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				for(int m = 0; m < increase_grid; m ++) {
					for(int n = 0; n < increase_grid; n ++) {
					    char ch = board[origin_row + m][origin_col + n];
		                if (ch != '.') {
	    					if (digit_is_existed[ch - '0'] == 1) {
    						    return false;
	    					} else {
							    digit_is_existed[ch - '0'] = 1;
						    }
		                }
					}
				}
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() <= 0 || board[0].size() <= 0) {
			return true;
		}

		return horizon_is_valid(board) && vertical_is_valid(board) && nine_grid_is_valid(board);
	}
};
