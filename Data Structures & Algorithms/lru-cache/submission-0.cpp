struct Node {
    int key;
    int value; 
    Node* next; 
    Node* prev;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {

private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head; 
    Node* tail; 

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        removeNode(node);
        addNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            existingNode->value = value;
            removeNode(existingNode);
            addNode(existingNode);
            return;
        }

        if (mp.size() == capacity) {
            Node* lruNode = tail->prev;
            mp.erase(lruNode->key);    
            removeNode(lruNode);       
            delete lruNode;            
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};
