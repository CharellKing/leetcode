class Solution {
public:
    void left(vector<string>& parents, string& parent, int total_parent, int parent_num, int sum) {
        parent.push_back('(');
        combine(parents, parent, total_parent, parent_num + 1, sum + 1);
        parent.pop_back();
    }
    
    void right(vector<string>& parents, string& parent, int total_parent, int parent_num, int sum) {
        parent.push_back(')');
        combine(parents, parent, total_parent, parent_num, sum - 1);
        parent.pop_back();
    }
    
    void combine(vector<string>& parents, string& parent, int total_parent, int parent_num, int sum) {
        if (0 == sum) {
            if (parent_num >= total_parent) {
                parents.push_back(parent);
            } else {
                left(parents, parent, total_parent, parent_num, sum);
            }
        } else if (sum > 0) {
            if (parent_num >= total_parent) {
                right(parents, parent, total_parent, parent_num, sum);
            } else {
                left(parents, parent, total_parent, parent_num, sum);
                right(parents, parent, total_parent, parent_num, sum);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
         vector<string> ret;
         string parent;
         combine(ret, parent, n, 0, 0);
         return ret;
    }
};
