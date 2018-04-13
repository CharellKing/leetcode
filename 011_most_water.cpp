class Solution {
public:
    int maxArea(vector<int>& height) {
        map<int, int> lefts, rights;
        int max_left = -1, max_right = -1;
        for(int i = 0; i < height.size(); i ++) {
            if (height[i] > max_left) {
                max_left = height[i];
                lefts.insert(make_pair(i, height[i]));
            }
        }
        
        for(int i = height.size() - 1; i >= 0; i --) {
            if (height[i] > max_right) {
                max_right = height[i];
                rights.insert(make_pair(i, height[i]));
            }
        }
        
        int max_area = 0;
        for(map<int, int>::iterator left_iter = lefts.begin(); lefts.end() != left_iter; left_iter ++) {
            for(map<int, int>::reverse_iterator right_iter = rights.rbegin(); rights.rend() != right_iter && left_iter->first < right_iter->first; right_iter ++) {
                int min_height = left_iter->second > right_iter->second ? right_iter->second : left_iter->second;
                int width = right_iter->first - left_iter->first;
                if (min_height * width > max_area) {
                    max_area = min_height * width;
                }
            }
        }
        return max_area;
    }
};
