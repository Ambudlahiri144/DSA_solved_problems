struct Node{
    Node* links[2];
    bool cointainsKey(int bit){
        return (links[bit] != NULL);
    }
    void put(int bit,Node* node){
        links[bit] = node;

    }
    Node* get(int bit){
        return links[bit];
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int n) {
        Node* node = root;
        for(int i = 31;i>=0;i--){
            int bit = (n >> i) & 1;
            if(!node->cointainsKey(bit)) node->put(bit,new Node());
            node = node->get(bit);
        }
        
    }
    int getMax(int n){
        Node* node = root;
        int maxi = 0;
        for(int i = 31;i>=0;i--){
            int bit = (n >> i) & 1;
            if(node->cointainsKey(1 - bit)){
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
            }
            else node = node->get(bit);

        }
        return maxi;
        
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oQ;
        for(int i = 0;i<q;i++){
            oQ.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oQ.begin(),oQ.end());
        vector<int> ans(q,0);
        int ind = 0;
        Trie trie;
        for(int i = 0;i<q;i++){
            int xi = oQ[i].second.first;
            int mi = oQ[i].first;
            int qind  = oQ[i].second.second;
            while(ind < n && nums[ind] <= mi){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) ans[qind] = -1;
            else ans[qind] = trie.getMax(xi);



        }
        return ans;
    }
};