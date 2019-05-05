// Author: xhdhr10000
// Date: 2019-04-29

#define MAX(X,Y,Z) ((X) > (Y) ? ((X)>(Z)?(X):(Z)) : ((Y)>(Z)?(Y):(Z)))

void inline swap(int *x, int *y) {
    int a = *x;
    *x = *y;
    *y = a;
}

typedef struct {
    int *data;
    int size;
    int count;
} MinHeap;

MinHeap* minHeapCreate() {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (int*)malloc(sizeof(int)*100);
    heap->size = 100;
    heap->count = 0;
    return heap;
}

void minHeapResize(MinHeap *heap) {
    heap->size *= 2;
    heap->data = (int*)realloc(heap->data, sizeof(int)*heap->size);
}

void minHeapInsert(MinHeap *heap, int x) {
    int p = ++heap->count;
    if (heap->count >= heap->size-1) minHeapResize(heap);
    heap->data[p] = x;
    while (p > 1 && heap->data[p] < heap->data[p/2]) {
        swap(&heap->data[p], &heap->data[p/2]);
        p /= 2;
    }
}

void minHeapRemove(MinHeap *heap, int x) {
    int i;
    for (i=1; i<=heap->count; i++)
        if (heap->data[i] == x) break;
    swap(&heap->data[i], &heap->data[heap->count]);
    heap->count--;
    while (i*2 <= heap->count && heap->data[i] > heap->data[i*2] ||
           i*2+1 <= heap->count && heap->data[i] > heap->data[i*2+1]) {
        if (i*2+1 <= heap->count && heap->data[i*2+1] < heap->data[i*2]) {
            swap(&heap->data[i], &heap->data[i*2+1]);
            i = i*2+1;
        } else {
            swap(&heap->data[i], &heap->data[i*2]);
            i = i*2;
        }
    }
}

int minHeapGetMin(MinHeap *heap) {
    return heap->data[1];
}

void minHeapFree(MinHeap *heap) {
    free(heap->data);
    free(heap);
}

typedef struct {
    int *data;
    MinHeap *heap;
    int size;
    int count;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    stack->heap = minHeapCreate();
    stack->data = (int*)malloc(sizeof(int)*100);
    stack->size = 100;
    stack->count = 0;
    return stack;
}

void minStackResize(MinStack *obj) {
    obj->size *= 2;
    obj->data = (int*)realloc(obj->data, sizeof(int)*obj->size);
}

void minStackPush(MinStack* obj, int x) {
    if (obj->count >= obj->size) minStackResize(obj);
    obj->data[obj->count++] = x;
    minHeapInsert(obj->heap, x);
}

void minStackPop(MinStack* obj) {
    obj->count--;
    minHeapRemove(obj->heap, obj->data[obj->count]);
}

int minStackTop(MinStack* obj) {
    if (obj->count == 0) return 0;
    return obj->data[obj->count-1];
}

int minStackGetMin(MinStack* obj) {
    return minHeapGetMin(obj->heap);
}

void minStackFree(MinStack* obj) {
    minHeapFree(obj->heap);
    free(obj->data);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
