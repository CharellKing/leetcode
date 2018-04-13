class Solution {
public:
    int build_tree(int begin, int end, unordered_map<int, int>& counts) {
        if (begin == end) {
            return 1;
        } else if (begin > end) {
            return 1;
        }
        
        int size = end - begin + 1;
        unordered_map<int, int>::iterator iter = counts.find(size);
        if (iter != counts.end()) {
            return iter->second;
        }
        
        int sum = 0;
        for(int i = begin; i <= end; i ++) {
            int left = build_tree(begin, i - 1, counts);
            int right = build_tree(i + 1, end, counts);
            sum += left * right;
        }
        counts.insert(make_pair(size, sum));
        return sum;
    }
    
    int numTrees(int n) {
        if (n <= 0) {
            return 0;
        }
        unordered_map<int, int> counts;
        return build_tree(1, n, counts);
    }
};
