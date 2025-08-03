class Solution {
public:
    char solve(vector<char>& val,char op){
        if(op == '!') return val[0] == 't'?'f':'t';
        if(op == '&'){
            for(char &ch:val){
                if(ch == 'f') return 'f';
            }
            return 't';
        }
        if(op == '|'){
            for(char &ch:val){
                if(ch == 't') return 't';
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;
        for(int i = 0;i<n;i++){
            if(expression[i] == ',') continue;
            if(expression[i] == ')'){
                vector<char> val;
                while(st.top() != '('){
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(val,op));
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top() == 't'?true:false;

        
        
    } 
};