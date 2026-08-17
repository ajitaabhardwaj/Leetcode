class LRUCache {
public:

    class Node{
        public:
            int key;
            int val;
            Node* next = NULL;
            Node* prev = NULL;
            
            Node(int k, int v){
                key = k;
                val = v;
            }
    };

    unordered_map<int, Node*> mp;
    int limit = 0;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    void bringahead(Node* node){
        if (head->next == node) {
            return;
        }
        Node* oldprev = node->prev;
        Node* oldnext = node->next;
        Node* oldfirst = head->next;
        head->next = node;
        node->prev = head;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
        node->next = oldfirst;
        oldfirst->prev = node;
        return;
    }

    void addnode(Node* newnode){
        Node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }

    Node* dellastnode(){
        Node* todel = tail->prev;
        Node* currlast = tail->prev->prev;
        currlast->next = tail;
        tail->prev = currlast;
        return todel;
    }

    void deloldnode(Node* oldnode){
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
        return;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* ans = mp[key];

        bringahead(ans);
        return ans->val;
    }
    
    void put(int key, int value) {
    
        if(mp.find(key) != mp.end()){
            Node* oldnode = mp[key];
            oldnode->val = value;
            bringahead(oldnode);
            return;
        }
        if(mp.size() == limit){
            Node* last = dellastnode();
            mp.erase(last->key);
            delete last;
        }
        Node* newnode = new Node(key, value);
        addnode(newnode);
        mp[key] = newnode;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */