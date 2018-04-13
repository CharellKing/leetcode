class MinStack {
private:
    list<multiset<int>::iterator> st;
    multiset<int> nums;
    
public:
    /** initialize your data structure here. */
    MinStack(){
    }
    
    void push(int x) {
        multiset<int>::iterator iter = nums.insert(x);
        st.push_back(iter);
    }
    
    void pop() {
        if (st.size() > 0) {
            nums.erase(st.back());
            st.pop_back();
        }
    }
    
    int top() {
        return *st.back();
    }
    
    int getMin() {
        return *nums.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */