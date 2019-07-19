// Author: xhdhr10000
// Date: 2019-07-17
struct HashMap {
    int key, value;
};

int prime(int n) {
    int i;
    n = n%2 ? n+2 : n+1;
    for (;; n+=2) {
        for (i=3; i*i<=n; i++)
            if (n % i == 0) break;
        if (i*i > n) return n;
    }
    return n;
}

int hash(struct HashMap *map, int key, int P) {
    int i = abs(key % P);
    while (map[i].key != key && map[i].key != 0) i = (i+1) % P;
    if (map[i].key == 0) map[i].key = key;
    return i;
}

int majorityElement(int* nums, int numsSize){
    int P = prime(numsSize);
    struct HashMap *map = (struct HashMap*)malloc(sizeof(struct HashMap)*P);
    memset(map, 0, sizeof(struct HashMap)*P);
    for (int i=0; i<numsSize; i++) {
        int idx = hash(map, nums[i], P);
        map[idx].value++;
        if (map[idx].value > numsSize/2) {
            int ret = map[idx].key;
            free(map);
            return ret;
        }
    }
    
    free(map);
    return -1;
}
