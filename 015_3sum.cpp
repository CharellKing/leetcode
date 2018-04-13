#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3) {
            return ret;
        }
        unordered_map<int, int> num_count;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++) {
            unordered_map<int, int>::iterator iter = num_count.insert(make_pair(nums[i], 0)).first;
            iter->second ++;
        }
        
        int first_sum = 0;
        for(int i = 0; i < nums.size() - 2 && nums[i] <= first_sum; i ++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int second_sum = first_sum - nums[i];
            num_count[nums[i]] --;
            for(int j = i + 1; j < nums.size() - 1 && nums[j] <= second_sum; j ++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                num_count[nums[j]] --;
                int third_sum = second_sum - nums[j];
                if (nums[j + 1] <= third_sum) {
                    unordered_map<int, int>::iterator iter = num_count.find(third_sum);
                    if (iter != num_count.end() && iter->second > 0) {
                        ret.push_back(vector<int>());
                        ret.back().push_back(nums[i]);
                        ret.back().push_back(nums[j]);
                        ret.back().push_back(third_sum);
                    }
                }
                num_count[nums[j]] ++;
            }
            num_count[nums[i]] ++;
        }
        
        return ret;
    }
};

