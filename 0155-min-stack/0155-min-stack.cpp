class MinStack {
public:
    long long mini;
    stack<long long> st;
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        long long lval = val;
        if(st.empty()){
            mini = lval;
            st.push(lval);

        }
        else{
            if(lval > mini) st.push(lval);
            else{
                st.push(2*lval - mini);
                mini = lval;
            }

        }
        
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) mini = 2 * mini - x;

        
    }
    
    int top() {
        if(st.empty()) return 0;
        long long x = st.top();
        if(mini < x) return (int)x;
        return (int)mini;

        
    }
    
    int getMin() {
        return mini;
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