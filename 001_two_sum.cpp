#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void initialize(const vector<int>& nums, unordered_map<int, int>& small_half_targets, unordered_map<int, int>& hash_nums, vector<int>& half_target_indexs, int target) {
        int half_target = target >> 1;
        for(int i = 0; i < nums.size(); i ++) {
            if (nums[i] <= half_target) {
                small_half_targets.insert(make_pair(nums[i], i));
                if (nums[i] == half_target && half_target_indexs.size() < 2) {
                    half_target_indexs.push_back(i);
                }
            }
            hash_nums.insert(make_pair(nums[i], i));
        }
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> small_half_targets;
        unordered_map<int, int> hash_nums;
        vector<int> half_target_indexs;

        initialize(nums, small_half_targets, hash_nums, half_target_indexs, target);

        if (target & 1 == 0 && half_target_indexs.size() >= 2) {
            return half_target_indexs;
        }

        vector<int> ret;
        for(unordered_map<int, int>::iterator half_iter = small_half_targets.begin(); small_half_targets.end() != half_iter; half_iter ++) {
            int other = target - half_iter->first;
            unordered_map<int, int>::iterator all_iter = hash_nums.find(other);
            if (hash_nums.end() != all_iter) {
                ret.push_back(half_iter->second);
                ret.push_back(all_iter->second);
                break;
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
