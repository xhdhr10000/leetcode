// Author: xhdhr10000
// Date: 2019-04-30

typedef struct {
    int *data;
    int *index;
} Array;

Array* arrayCreate(int *array, int size) {
    Array *ret = (Array*)malloc(sizeof(Array));
    ret->data = array;
    ret->index = (int*)malloc(sizeof(int)*size);
    for (int i=0; i<size; i++) ret->index[i] = i;
    return ret;
}

void arrayFree(Array *a) {
    free(a->index);
    free(a);
}

void inline swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void sort(Array *d, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && d->data[a]<=d->data[b]) a++;
        if (a<b) {
            swap(&d->data[a], &d->data[b]);
            swap(&d->index[a], &d->index[b]);
        }
        while (a<b && d->data[a]<=d->data[b]) b--;
        if (a<b) {
            swap(&d->data[a], &d->data[b]);
            swap(&d->index[a], &d->index[b]);
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*ASize);
    Array *a = arrayCreate(A, ASize);
    Array *b = arrayCreate(B, BSize);
    sort(a, 0, ASize-1);
    sort(b, 0, BSize-1);
    int *hash = (int*)malloc(sizeof(int)*ASize);
    memset(hash, 0, sizeof(int)*ASize);
    int i = 0, j;
    for (j=0; j<BSize; j++) {
        while (i<ASize && a->data[i] <= b->data[j]) i++;
        if (i == ASize) break;
        ret[b->index[j]] = a->data[i];
        hash[i] = 1;
        i++;
    }
    i = 0;
    for (; j<BSize; j++) {
        while (hash[i]) i++;
        ret[b->index[j]] = a->data[i];
        i++;
    }
    
    *returnSize = ASize;
    arrayFree(a);
    arrayFree(b);
    free(hash);
    return ret;
}



