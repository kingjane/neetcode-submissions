class MinStack {
    stack<int> data, minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        data.push(val);
        if (minStack.empty() || val < minStack.top()) minStack.push(val);
        else minStack.push(minStack.top());
    }
    
    void pop() {
        minStack.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
     return minStack.top();   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */