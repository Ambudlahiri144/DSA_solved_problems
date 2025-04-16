class Solution {
public:

    bool isValid(string s) {
        stack<int> s1;
        for(auto i:s){
            if(i == '(' || i == '{' || i == '[') s1.push(i);
            else{
                if(s1.size() == 0) return false;
                char ch = s1.top();
                s1.pop();
                if(i == ')' && ch == '(' || i == '}' && ch == '{' || i == ']' && ch == '[') continue;
                else return false;
            }
        }
        return s1.empty();
        
    }
};