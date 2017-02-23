class MyQueue {
public:
    /** Initialize your data structure here. */
    // Improved solution : using a lazy refill operation
    // average T(n) = O(1)
    stack<int> s_push;
    stack<int> s_pop;
    
    MyQueue() {
        ;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s_push.push(x);
    }
    
    void refill_stack(){
        while (!s_push.empty()){
            s_pop.push(s_push.top());
            s_push.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s_pop.empty())
            refill_stack();
        if (s_pop.empty())
            return -1;
        
        int temp = s_pop.top();
        s_pop.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (s_pop.empty())
            refill_stack();
        if (s_pop.empty())
            return -1;
        return s_pop.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s_pop.empty() && s_push.empty();
    }
};
