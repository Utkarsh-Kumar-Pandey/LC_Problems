class MyStack {
private:
    queue<int> q;
    // consist front and rear
public:
    MyStack() {}

    void push(int x) {
        // Usage of queue predefined functions push pop
        int length = q.size();
        q.push(x);

        // push the previous element after the new one and simultaneously
        // popping out
        for (int i = 0; i < length; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        // Empty condition
        if (q.empty()) {
            return -1;
        }
        int res = q.front();
        q.pop();
        return res;
    }
    int top() {
        if (q.empty()) {
            return -1;
        }
        return q.front();
    }
    bool empty() { return (q.empty()); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */