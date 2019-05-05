// Author: xhdhr10000
// Date: 2019-04-30
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *data;
    int *index;
    int count;
    int max;
} Heap;

Heap* heapCreate(int size) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->data =  (int*)malloc(sizeof(int)*(size+1));
    heap->index = (int*)malloc(sizeof(int)*(size+1));
    heap->count = 0;
    heap->max = -0x7fff;
    return heap;
}

void heapFree(Heap *heap) {
    free(heap->data);
    free(heap);
}

void inline swap(int *x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void heapInsert(Heap *heap, int x, int i) {
    int p = ++heap->count;
    heap->data[p] = x;
    heap->index[p] = i;
    if (x > heap->max) heap->max = x;
    while (p > 1 && heap->data[p] < heap->data[p/2]) {
        swap(&heap->data[p], &heap->data[p/2]);
        swap(&heap->index[p], &heap->index[p/2]);
        p /= 2;
    }
}

void heapPop(Heap *heap) {
    int p = 1;
    swap(&heap->data[1], &heap->data[heap->count]);
    swap(&heap->index[1], &heap->index[heap->count]);
    heap->count--;
    while (p*2 <= heap->count && heap->data[p] > heap->data[p*2] ||
          p*2+1 <= heap->count && heap->data[p] > heap->data[p*2+1]) {
        if (p*2+1 <= heap->count && heap->data[p*2+1] < heap->data[p*2]) {
            swap(&heap->data[p], &heap->data[p*2+1]);
            swap(&heap->index[p], &heap->index[p*2+1]);
            p = p*2+1;
        } else {
            swap(&heap->data[p], &heap->data[p*2]);
            swap(&heap->index[p], &heap->index[p*2]);
            p = p*2;
        }
    }
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*2);
    Heap *heap = heapCreate(numsSize);
    int *indexes = (int*)malloc(sizeof(int)*numsSize);
    for (int i=0; i<numsSize; i++) {
        indexes[i] = 0;
        heapInsert(heap, nums[i][0], i);
    }
    ret[0] = heap->data[1];
    ret[1] = heap->max;
    while (indexes[heap->index[1]] < numsColSize[heap->index[1]] - 1) {
        int i = heap->index[1];
        indexes[i]++;
        heapPop(heap);
        heapInsert(heap, nums[i][indexes[i]], i);
        if (heap->max - heap->data[1] < ret[1] - ret[0]) {
            ret[0] = heap->data[1];
            ret[1] = heap->max;
        }
    }
    
    heapFree(heap);
    *returnSize = 2;
    return ret;
}



