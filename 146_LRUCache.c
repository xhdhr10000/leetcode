// Author: xhdhr10000
// Date: 2019-05-16

typedef struct Node {
    int key;
    int val;
    struct Node *prev, *next, *up, *down;
} Node;

typedef struct {
    Node **hash;
    Node *head, *tail;
    int capacity, size, count;
} LRUCache;

int next_prime(int x) {
    int i, j;
    for (i=x; ; i++) {
        if (i % 2 == 0) continue;
        for (j=3; j<sqrt(i)+1; j+=2) {
            if (i % j == 0) break;
        }
        if (j >= sqrt(i)+1) return i;
    }
    return -1;
}

LRUCache* lRUCacheCreate(int capacity) {
    printf("%s, capacity=%d\n", __func__, capacity);
    LRUCache *cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = next_prime(capacity+1);
    cache->count = 0;
    cache->hash = (Node**)malloc(sizeof(Node*)*cache->size);
    memset(cache->hash, 0, sizeof(Node*)*cache->size);
    cache->head = cache->tail = NULL;
    return cache;
}

void lRUCacheRefresh(LRUCache *obj, Node *n) {
    printf("%s, key=%d\n", __func__, n->key);
    if (n == obj->head) return;
    if (n == obj->tail) obj->tail = n->prev;
    if (n->prev) n->prev->next = n->next;
    if (n->next) n->next->prev = n->prev;
    n->next = obj->head;
    obj->head->prev = n;
    obj->head = n;
}

Node* lRUCacheFind(LRUCache *obj, int key) {
    printf("%s, key=%d\n", __func__, key);
    Node *n = obj->hash[key % obj->size];
    while (n && n->key != key) n = n->down;
    return n;
}

int lRUCacheGet(LRUCache* obj, int key) {
    printf("%s, key=%d\n", __func__, key);
    Node *n = lRUCacheFind(obj, key);
    if (n) {
        lRUCacheRefresh(obj, n);
        return n->val;
    }
    return -1;
}

void lRUCacheExpireOne(LRUCache *obj) {
    printf("%s, count=%d\n", __func__, obj->count);
    if (!obj->tail) return;
    Node *n = obj->tail;
    
    /* Horizontal */
    if (n == obj->head) obj->head = NULL;
    obj->tail = n->prev;
    if (n->prev) n->prev->next = n->next;
    if (n->next) n->next->prev = n->prev;
    
    /* Vertical */
    if (n == obj->hash[n->key % obj->size]) obj->hash[n->key % obj->size] = n->down;
    if (n->up) n->up->down = n->down;
    if (n->down) n->down->up = n->up;
    
    obj->count--;
}

Node* lRUCacheAllocNode(int key, int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->val = value;
    node->prev = NULL;
    node->next = NULL;
    node->up   = NULL;
    node->down = NULL;
    return node;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    printf("%s, key=%d, value=%d\n", __func__, key, value);
    Node *node = lRUCacheFind(obj, key);
    if (node) {
        node->val = value;
        lRUCacheRefresh(obj, node);
        return;
    }
    
    if (obj->count >= obj->capacity) lRUCacheExpireOne(obj);
    node = lRUCacheAllocNode(key, value);
    if (!obj->hash[key % obj->size]) {
        obj->hash[key % obj->size] = node;
    } else {
        Node *p = obj->hash[key % obj->size];
        while (p && p->key != key && p->down) p = p->down;
        if (p->key == key) {
            p->val = value;
        } else {
            p->down = node;
            node->up = p;
        }
    }
    
    if (obj->count == 0) obj->head = obj->tail = node;
    else {
        node->next = obj->head;
        obj->head->prev = node;
        obj->head = node;
    }
    obj->count++;
}

void lRUCacheFree(LRUCache* obj) {
    printf("%s, count=%d\n", __func__, obj->count);
    Node *n = obj->head, *p;
    while (n) {
        p = n;
        n = n->next;
        free(p);
    }
    free(obj->hash);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
