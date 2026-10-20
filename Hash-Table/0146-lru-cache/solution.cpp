class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int key_, int val_){
            key = key_;
            val = val_;
        }
    };

    unordered_map<int, Node*>m;
    int maxSize;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        maxSize = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node; 
        node->prev = head;
        temp->prev = node;
        node->next = temp;
    }

    void deleteNode(Node* delnode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* node = m[key];
            m.erase(key);
            deleteNode(node);
        }
        if(m.size() == maxSize){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
