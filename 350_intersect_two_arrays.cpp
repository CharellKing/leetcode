class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> set1, set2;
        for(int i = 0; i < nums1.size(); i ++) {
            set1.insert(make_pair(nums1[i], 0));
            set1[nums1[i]] ++;
        }
        
        for(int i = 0; i < nums2.size(); i ++) {
            set2.insert(make_pair(nums2[i], 0));
            set2[nums2[i]] ++;
        }
        
        vector<int> ret;
        unordered_map<int, int> &short_set = set1, &long_set = set2;
        if (short_set.size() > long_set.size()) {
            swap(short_set, long_set);
        }
        
        for(unordered_map<int, int>::iterator iter = short_set.begin(); short_set.end() != iter; iter ++) {
            unordered_map<int, int>::iterator other_iter = long_set.find(iter->first);
            if (long_set.end() != other_iter) {
                int count = iter->second > other_iter->second ? other_iter->second : iter->second;
                for(int i = 0; i < count; i ++) {
                    ret.push_back(iter->first);
                }
            }
        }
        return ret;
    }
};
