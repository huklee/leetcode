class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1;
    stack<int> s2;
    bool mFlag;
    const bool PUSH_MODE = false;
    const bool POP_MODE = true;
    
    MyQueue() {
        mFlag = PUSH_MODE;
    }
    
    void switch_mode(bool mode){
        if (mFlag != mode && mode == PUSH_MODE){
            while (!s2.empty()){
                int elem = s2.top();
                s2.pop();
                s1.push(elem);
            }
        }
        if (mFlag != mode && mode == POP_MODE){
            while (!s1.empty()){
                int elem = s1.top();
                s1.pop();
                s2.push(elem);
            }
        }
        mFlag = mode;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        switch_mode(PUSH_MODE);
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        switch_mode(POP_MODE);
        if (s2.empty())
            return -1;
        else{
            int res = s2.top();
            s2.pop();
            return res;
        }
    }
    
    /** Get the front element. */
    int peek() {
        switch_mode(POP_MODE);
        if (s2.empty())
            return -1;
        else
            return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (mFlag == PUSH_MODE)
            return s1.empty();
        else
            return s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */