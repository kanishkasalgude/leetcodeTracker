struct Node
{
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        value = val_;
        cnt = 1;    
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;

    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        head->next = node;
        temp->prev = node;
        node->next = temp;
        node->prev = head;
        size++;
    }

    void removeNode(Node* delNode){
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    int maxSizeCache, currSize, minFreq;
    unordered_map<int, Node*>keyNode;
    unordered_map<int, List*>freqListMap;
    public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[minFreq]->size == 0){
            minFreq++;
        }
        
        List* nextHigherFreq = new List();
        if(freqListMap.find(node->cnt+1) != freqListMap.end()){
            nextHigherFreq = freqListMap[node->cnt+1];
        }

        node->cnt += 1;
        nextHigherFreq->addFront(node);
        freqListMap[node->cnt] = nextHigherFreq;
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int value = node->value;
            updateFreqListMap(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }else{
            if(currSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                Node* nodeToEvict = list->tail->prev;
                keyNode.erase(nodeToEvict->key);
                list->removeNode(nodeToEvict);
                delete nodeToEvict;
                currSize--;
            }
            currSize++;
            minFreq = 1;
            Node* node = new Node(key, value);
            List* list = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) list = freqListMap[minFreq];
            list->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
