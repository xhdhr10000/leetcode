// Author: xhdhr10000
// Date: 2019-05-21

typedef struct {
    int val;
    int count;
} Node;

void sort(int *d, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && d[a]<=d[b]) a++;
        if (a<b) {
            c=d[a];d[a]=d[b];d[b]=c;
        }
        while (a<b && d[a]<=d[b]) b--;
        if (a<b) {
            c=d[a];d[a]=d[b];d[b]=c;
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

bool isNStraightHand(int* hand, int handSize, int W){
    if (handSize % W) return false;
    int len = handSize / W;
    Node *q = (Node*)malloc(sizeof(Node)*len);
    int head = 0, tail = 0, j = 0;
    
    sort(hand, 0, handSize-1);
    for (int i=0; i<handSize; i++) {
        if (head == tail) {
            if (tail >= len) return false;
            q[tail].val = hand[i];
            q[tail].count = 1;
            tail++;
            j++;
        } else if (q[head].val+1 == hand[i]) {
            q[head].val++;
            q[head].count++;
            if (q[head].count == W) head++;
            j = head + 1;
        } else if (j >= tail) {
            if (tail >= len) return false;
            q[tail].val = hand[i];
            q[tail].count = 1;
            tail++;
            j++;
        } else if (q[j].val+1 == hand[i]) {
            q[j].val++;
            q[j].count++;
            j++;
        } else return false;
    }
    
    free(q);
    return true;
}



