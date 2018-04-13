class Solution {
public:
    vector<int> getVersion(const string& version) {
        vector<int> nums;
        int num = 0;
        bool is_push = true;
        for(int i = 0; i < version.size(); i ++) {
            if (version[i] == '.') {
                nums.push_back(num);
                is_push = true;
                num = 0;
            } else {
                num = num * 10 + version[i] - '0';
                is_push = false;
            }
        }
        
        if (false == is_push) {
            nums.push_back(num);   
        }
        
        for(int i = nums.size() - 1; i >= 0 && nums[i] == 0; i --) {
            nums.pop_back();
        }
        
        return nums;
    }
    
    int compareVersion(const string& version1, const string& version2) {
        vector<int> version_nums1 = getVersion(version1);
        vector<int> version_nums2 = getVersion(version2);
        
        int i = 0;
        while (i < version_nums1.size() && i < version_nums2.size()) {
            if (version_nums1[i] > version_nums2[i]) return 1;
            if (version_nums1[i] < version_nums2[i]) return -1;
            i ++;
        }
        
        if (i < version_nums1.size()) return 1;
        if (i < version_nums2.size()) return -1;
        
        return 0;
    }
};