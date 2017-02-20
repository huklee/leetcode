class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    bool mFlag;
    const bool Q1_MODE = false;
    const bool Q2_MODE = true;

    /** Initialize your data structure here. */
    MyStack() {
        mFlag = Q1_MODE;
    }
    
    /** Push element x onto stack. */
    // O(n) operation
    void push(int x) {
        if(mFlag == Q1_MODE){
            q2.push(x);
            while(!q1.empty()){
                int elem = q1.front();
                q1.pop();
                q2.push(elem);
            }
        }
        else{
            q1.push(x);
            while(!q2.empty()){
                int elem = q2.front();
                q2.pop();
                q1.push(elem);
            }
        }
        mFlag = (mFlag + 1)%2;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // O(1) operation
    int pop() {
        if(mFlag == Q1_MODE){
            int elem = q1.front();
            q1.pop();
            return elem;
        }
        else{
            int elem = q2.front();
            q2.pop();
            return elem;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(mFlag == Q1_MODE)
            return q1.front();
        else
            return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(mFlag == Q1_MODE)
            return q1.empty();
        else
            return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */