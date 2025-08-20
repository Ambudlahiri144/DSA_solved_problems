class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map;
        for(int i = 0;i<s.size();i++){
            char s1 = s[i];
            char t1 = t[i];
            if(map.count(s1)){
                if(map[s1] != t1) return false;
            }
            else{
                for(auto& i:map){
                    if(i.second == t1) return false;
                }
                map[s1] = t1;
            }
        }
        return true;
        
    }
};