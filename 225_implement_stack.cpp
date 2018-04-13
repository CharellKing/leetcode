class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        vector<int> values;
        while (q.size() > 0) {
            values.push_back(q.front());
            q.pop();
        }
        
        q.push(x);
        for(int i = 0; i < values.size(); i ++) {
            q.push(values[i]);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};