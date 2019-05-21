// Author: xhdhr10000
// Date: 2019-05-20
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    int *data;
    int size;
    int count;
} Heap;

Heap* heapCreate() {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 256;
    heap->count = 0;
    heap->data = (int*)malloc(sizeof(int)*heap->size);
    return heap;
}

void heapFree(Heap *h) {
    free(h->data);
    free(h);
}

void inline swap(int *x, int *y) {
    int c = *x; *x = *y; *y = c;
}

void heapInsert(Heap *h, int x) {
    if (h->count+1 >= h->size) {
        h->size *= 2;
        h->data = (int*)realloc(h->data, sizeof(int)*h->size);
    }
    int i = ++h->count;
    h->data[i] = x;
    while (i > 1 && h->data[i] < h->data[i/2]) {
        swap(&h->data[i], &h->data[i/2]);
        i /= 2;
    }
}

int heapPop(Heap *h) {
    if (h->count == 0) return 0;
    int ret = h->data[1];
    swap(&h->data[1], &h->data[h->count]);
    h->count--;
    int i = 1;
    while (i*2 <= h->count && h->data[i*2] < h->data[i] ||
          i*2+1 <= h->count && h->data[i*2+1] < h->data[i]) {
        if (i*2+1 <= h->count && h->data[i*2+1] < h->data[i*2]) {
            swap(&h->data[i], &h->data[i*2+1]);
            i = i*2+1;
        } else {
            swap(&h->data[i], &h->data[i*2]);
            i = i*2;
        }
    }
    return ret;
}

struct ListNode* allocNode() {
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->next = NULL;
    return ret;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode *ret = allocNode(), *p = ret;
    Heap *h = heapCreate();
    bool ne = true;
    while (ne) {
        ne = false;
        for (int i=0; i<listsSize; i++) {
            if (!lists[i]) continue;
            ne = true;
            heapInsert(h, lists[i]->val);
            lists[i] = lists[i]->next;
        }
        if (h->count) {
            p->next = allocNode();
            p = p->next;
            p->val = heapPop(h);
        }
    }
    while (h->count) {
        p->next = allocNode();
        p = p->next;
        p->val = heapPop(h);
    }
    
    heapFree(h);
    return ret->next;
}



