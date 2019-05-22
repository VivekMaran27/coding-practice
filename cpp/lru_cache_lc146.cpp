using namespace std;
typedef struct DNode
{
    int key;
    int value;
    struct DNode *prev;
    struct DNode *next;
}DNode;

class LRUCache {
    
private:
    int m_capacity;
    int size;
    std::map<int, DNode*> keyDNodeMap; 
    DNode *head;
    DNode *tail;
    
public:
    LRUCache(int capacity) {
          head = NULL;
          tail = NULL;
          size = 0;
          m_capacity = capacity;
          cout<<"capacity: "<<capacity<<endl;
    }
    
    /* Get value from cache */
    int get(int key) {
        int result = -1;
        int value = -1;
        // cout<<"get()++"<<endl;
        // cout<<"Get->Key: "<<key<<endl;
        if(keyDNodeMap.find(key) != keyDNodeMap.end())
        {
            // cout<<"Key found"<<endl;
            value = keyDNodeMap[key]->value;
            DeleteCacheNode(key); /* Delete the node */
            // cout<<"Deleted cache node"<<endl;
            insertMRUNode(key, value); /* Insert as most recently used node */
            result = value;  
        }
        else
        {
            result = -1;
        }
        // printLL();
        // cout<<"get()--"<<endl;
        return result;
    }
    
    /* Put key value into cache */
    void put(int key, int value) {
        
        // cout<<"put()++"<<endl;
        // cout<<"Put->Key: "<<key<<" current size: "<<size<<endl;
              
        /* Delete the node if already present, we will
        insert a new one at the beggining */
        if(keyDNodeMap.find(key) != keyDNodeMap.end())
            DeleteCacheNode(key);
        insertMRUNode(key, value); 
        
        /* Check size and evict */
        if(size > m_capacity)
        {
            // cout<<"Size: "<<size<<" equals capcity "
            //     <<m_capacity<<" ,hence evicting"<<endl;
            deleteLRUNode();
        }
        //printLL();
        // cout<<"put()--"<<endl;
    }
    
    /* Delete the cache node with the given key*/
    void DeleteCacheNode(int key)
    {
        DNode* node = keyDNodeMap[key];
        deleteDNode(node);
        keyDNodeMap.erase(key);
        //delete node;
        --size;        
    }
    
    /* Insert cache node with the given key*/
    void insertMRUNode(int key, int val)
    {
        /* Create node */
        DNode *node = new DNode;
        node->value = val;
        node->key = key;

        /* Insert at beginning */
        insertAsFirstDNode(node);

        /* Add node to hashmap */
        keyDNodeMap[key] = node;

        /* Increase the occupied space of the cache */
        ++size;  
    }
    
    /* Delete last node in cache */
    void deleteLRUNode()
    {
        int key = 0;
        key = deleteLastDNode();
        // cout<<"Deleted LRU node: "<<key<<endl;
        keyDNodeMap.erase(key);
        --size;        
        // cout<<"Removed cached node: "<<key<<" from map"<<endl;
    }
    
    /* Delete node */
    void deleteDNode(DNode * node)
    {
        
        DNode *prev = node->prev;
        DNode *next = node->next;
        
        if(node == head)
        {
            head = node->next;
            if(head) head->prev = NULL;            
        }
        else if (node == tail)
        {
            tail = tail->prev;
            tail->next = NULL;            
        }
        else
        {
            prev->next = next;
            next->prev = prev;            
        }
    }
    
    /* Insert as first node in doubly linked list */
    void insertAsFirstDNode(DNode *node)
    {
        if(head == NULL)
        {
            head = tail = node;
            node->next = node->prev = NULL;
        }
        else
        {
            node->next = head;
            node->prev = head->prev;
            head->prev = node;
            head = node;
        }
        
        /* If it is last node */
        if(node->next == NULL)
            tail = node;
    }
    
    /* Delete last node of doubly linked list */
    int deleteLastDNode()
    {
        DNode* prev = tail->prev;
        DNode* next = tail->next;
        int key = tail->key;
//        delete tail;
        tail = prev;
        if(tail) tail->next = next;
        return key;
    }
    
    // void printLL()
    // {
    //     cout<<"keys: ";
    //     DNode* temp = head;
    //     while(temp != NULL)
    //     {
    //         cout<<temp->key;
    //         cout<<" ";
    //         temp = temp->next;
    //     }
    //     cout<<endl;
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
