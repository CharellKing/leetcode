class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> integer_poses;
        vector<pair<int, int> > pos_integers;
        for(int i = 0; i < nums.size(); i ++) {
            unordered_map<int, int>::iterator iter = integer_poses.find(nums[i]);
            if (integer_poses.end() == iter) {
               integer_poses.insert(make_pair(nums[i], i)); 
               pos_integers.push_back(make_pair(i, nums[i]));
            } else {
                if (i - iter->second <= k) {
                    return true;
                } else {
                    for(vector<pair<int, int>>::iterator pos_iter = pos_integers.begin(); pos_integers.end() != pos_iter;){
                        if (pos_iter->first <= iter->second) {
                            integer_poses.erase(pos_iter->second);
                            pos_iter = pos_integers.erase(pos_iter);
                        } else {
                            pos_iter ++;
                        }
                    }
                    integer_poses.insert(make_pair(nums[i], i));
                    pos_integers.push_back(make_pair(i, nums[i]));
                }
            }
        }
        return false;
    }
};