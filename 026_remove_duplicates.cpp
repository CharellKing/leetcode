class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, move_steps = 0;		
		for(int i = 1; i < nums.size(); i ++) {
			if (nums[i] == nums[i - 1]) {
				move_steps ++;
			} else {
				nums[i - move_steps] = nums[i];
			}
		}
		return nums.size() - move_steps;
	}
};
