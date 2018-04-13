class Solution {
public:
    bool is_operator(const string& token) {
        return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');    
    }
    
    int get_number(const string& token) {
        int number = 0;
        stringstream ss;
        ss << token;
        ss >> number;
        return number;
    }
    
    int calc(int left_operand, int right_operand, const string& cal_operator) {
        int ret = INT_MAX;
        switch (cal_operator[0]) {
        case '+':
            ret = left_operand + right_operand;
            break;
        case '-':
            ret = left_operand - right_operand;
            break;
        case '*':
            ret = left_operand * right_operand;
            break;
        case '/':
            if (right_operand != 0) {
                ret = left_operand / right_operand;
            }
            break;
        };
        return ret;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        for(int i = 0; i < tokens.size(); i ++) {
            if (tokens[i].size() > 0) {
                if (is_operator(tokens[i])) {
                    if (vals.size() >= 2) {
                        int right_operand = vals.top();
                        vals.pop();
                        int left_operand = vals.top();
                        vals.pop();
                        int ret = calc(left_operand, right_operand, tokens[i]);
                        vals.push(ret);
                    }
                        
                } else {
                    vals.push(get_number(tokens[i]));
                }
            }
        }
        return vals.top();
    }
};