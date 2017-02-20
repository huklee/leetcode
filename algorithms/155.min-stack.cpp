class MinStack {
public:
    /** initialize your data structure here. */
    // two stacks solutions : number stack + minimum stack
    stack<int> numStack;
    stack<int> minStack;
    MinStack() {
        ;   
    }
    
    // T(N) = O(1) 
    void push(int x) {
        numStack.push(x);
        if (minStack.size() != 0 && minStack.top() <= x)
            minStack.push(minStack.top());
        else
            minStack.push(x);
    }
    
    // T(N) = O(1) 
    void pop() {
        numStack.pop();
        minStack.pop();
    }
    
    // T(N) = O(1) 
    int top() {
        if (numStack.size() == 0)
            return -1;
        return numStack.top();
    }
    
    // T(N) = O(1) 
    int getMin() {
        if (minStack.size() == 0)
            return -1;
        return minStack.top();
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
