class Solution {
public:
    bool isPal(string s,int start,int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    void func(int index,string s,vector<string> &res, vector<vector<string>> &path){
        if(index == s.size()){
            path.push_back(res);
            return;
        }
        for(int i = index;i < s.size();i++){
            if(isPal(s,index,i)){
                res.push_back(s.substr(index,i-index+1));
                func(i+1,s,res,path);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> path;
        vector<string> res;
        func(0,s,res,path);
        return path;
        
    }
};