// Solution using 1 Queue 
class MyStack {
public:
    queue<int> q1;

    /** Initialize your data structure here. */
    MyStack() {
        ;
    }
    
    /** Push element x onto stack. */
    // O(n) operation
    void push(int x) {
        q1.push(x);
        for (unsigned int i=0; i < q1.size() - 1; i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // O(1) operation
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};
