class MyQueue {
private:
    stack<int> st;
    stack<int> st1;

public:
    MyQueue() {}

    void push(int x) { st.push(x); }

    int pop() {
        if (st1.empty()) {
            while (!st.empty()) {
                st1.push(st.top());
                st.pop();
            }
        }
        int res = st1.top();
        st1.pop();
        return res;
    }

    int peek() {
        if (st1.empty()) {
            while (!st.empty()) {
                st1.push(st.top());
                st.pop();
            }
        }
        int res = st1.top();
        return res;
    }

    bool empty() {
        return st.empty() && st1.empty();
        ;
    }
};
