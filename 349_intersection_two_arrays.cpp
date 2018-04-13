class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for(int i = 0; i < nums1.size(); i ++) {
            set1.insert(nums1[i]);
        }
        
        for(int i = 0; i < nums2.size(); i ++) {
            set2.insert(nums2[i]);
        }
        
        unordered_set<int> &long_set = set1, &short_set = set2;
        if (set1.size() < set2.size()) {
            swap(long_set, short_set);
        }
        
        vector<int> ret;
        for(unordered_set<int>::iterator iter = short_set.begin(); short_set.end() != iter; iter ++) {
            if (long_set.find(*iter) != long_set.end()) {
                ret.push_back(*iter);
            }
        }
        return ret;
    }
};
