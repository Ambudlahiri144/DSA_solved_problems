class MyQueue {
public:
    stack<int> S1,S2;
    MyQueue() {}
    
    void push(int x) {
        S1.push(x);
        
    }
    
    int pop() {
        peek();
        int x = S2.top();
        S2.pop();
        return x;


        
    }
    
    int peek() {
        if (S2.empty()) {
            while (!S1.empty()) {
                S2.push(S1.top()); 
                S1.pop();          
            }
        }
        return S2.top();

        
    }
    
    bool empty() {
        return S1.empty() && S2.empty(); 
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */