class node{
    public:
    node* next;
    node* prev;
    int key;
    int val;
    
    
    node(int key,int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev= NULL;
    }
};

class LRUCache {
public:
    node* head = new node(0,0);
    node* tail = new node(0,0);
    int cap;
    unordered_map<int,node*>mpp;
    void deletenode(node* help){
        node* helpnext = help->next;
        node* helpprev = help->prev;
        
        helpprev->next = helpnext;
        helpnext->prev = helpprev;
    }
    
    void addnode(node* help){
        node* node1 = head->next;
        help->prev = head;
        help->next = node1;
        node1->prev = help;
        head->next = help;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev= head;
    }
    
    int get(int key) {
        
        if(mpp.find(key) != mpp.end()){
            node* ex = mpp[key];
            int ans = ex->val;
            deletenode(mpp[key]);
             addnode(mpp[key]);
            //mpp.erase(key);
           
            mpp[key] = head->next;
            
            return ans;
        
        }else{
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
           deletenode(mpp[key]);
            //mpp.erase(key);
        }else if(mpp.size()==cap){
             mpp.erase(tail->prev->key);
            deletenode(tail->prev);
           
        }
        
        
        addnode(new node(key,value));
        mpp[key] = head->next;
        
        return ;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */