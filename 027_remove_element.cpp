class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int move_step = 0;		
		for(int i = 0; i < nums.size(); i ++) {
			if (nums[i] == val) {
				move_step ++;
			} else {
				nums[i - move_step] = nums[i];
			}
		}
		return nums.size() - move_step;
	}
};
