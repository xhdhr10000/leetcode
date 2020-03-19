// Author: xhdhr10000
// Date: 2020-03-18

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        p = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q[1-p].push(x);
        while (!q[p].empty()) {
            q[1-p].push(q[p].front());
            q[p].pop();
        }
        p = 1-p;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = q[p].front();
        q[p].pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return q[p].front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[p].empty();
    }
private:
    std::queue<int> q[2];
    int p;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
