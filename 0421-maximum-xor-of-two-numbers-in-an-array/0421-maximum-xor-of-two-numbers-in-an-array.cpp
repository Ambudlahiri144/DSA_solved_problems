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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie trie;
        for(int i = 0;i<n;i++){
            trie.insert(nums[i]);
        }
        int maxi = 0;
        for(int j = 0;j<n;j++){
            maxi = max(maxi,trie.getMax(nums[j]));
        }
        return maxi;
        
    }
};