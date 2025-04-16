class LRUCache {
public:
    class Node{
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    unordered_map<int,Node*> mpp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    void insertAfterHead(Node* node){
        Node* currafterHead = head->next;
        head->next = node;
        node->next = currafterHead;
        node->prev = head;
        currafterHead->prev = node;
    }
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* afterNode = node->next;  
        afterNode->prev = prevNode;
        prevNode->next = afterNode;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* resNode = mpp[key];
            int ans = resNode -> val;

            mpp.erase(key);
            deleteNode(resNode);
            insertAfterHead(resNode);

            mpp[key] = head -> next;
            return ans;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            mpp.erase(key);
            deleteNode(node);
              
        }
       
        if(mpp.size() == cap){
            mpp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        Node* res = new Node(key,value);
        insertAfterHead(res);
        mpp[key] = head->next;
            
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */