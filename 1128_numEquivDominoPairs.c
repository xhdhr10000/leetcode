// Author: xhdhr10000
// Date: 2019-07-21

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

void sort(int *d, int x, int y) {
    int a=x, b=y, c;

    while (a<b) {
        while (a<b && d[a]<=d[b]) a++;
        if (a<b) {
            c=d[a]; d[a]=d[b]; d[b]=c;
        }
        while (a<b && d[a]<=d[b]) b--;
        if (a<b) {
            c=d[a]; d[a]=d[b]; d[b]=c;
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

bool equal(int *x1, int *x2, int size) {
    int i;
    for (i=0; i<size; i++)
        if (x1[i] != x2[i]) break;
    return i == size+1;
}

struct Hash {
    int v;
    int c;
};

int hash(struct Hash *h, int **d, int idx, int *sizes, int P) {
    int sum = 0, mul = 1, i;
    sort(d[idx], 0, sizes[idx]-1);
    for (i=0; i<sizes[idx]; i++) {
        sum = (sum + d[idx][i]*mul) % P;
        mul *= 10;
    }
    for (i=0; i<sizes[idx]; i++) printf("%d ", d[idx][i]);
    printf(": %d\n", sum);
    i = sum;
    while (h[i].v && (sizes[h[i].v-1] != sizes[idx] || memcmp(d[h[i].v-1], d[idx], sizes[idx]*sizeof(int)))) i = (i+1) % P;
    printf("i=%d\n", i);
    if (h[i].v != 0) return i;
    h[i].v = idx+1;
    h[i].c = 1;
    printf("%d:%d\n", i, h[i].v);
    return -1;
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int ans = 0;
    int P = prime(dominoesSize);
    struct Hash *h = (struct Hash*)malloc(sizeof(struct Hash)*P);
    
    printf("P=%d\n", P);
    memset(h, 0, sizeof(struct Hash)*P);
    for (int i=0; i<dominoesSize; i++) {
        int x = hash(h, dominoes, i, dominoesColSize, P);
        if (x >= 0) {
            ans += h[x].c;
            h[x].c++;
        }
    }
    
    return ans;
}
