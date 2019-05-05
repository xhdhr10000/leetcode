// Author: xhdhr10000
// Date: 2019-05-04

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point d[8];
    int p;
} RoundList;

RoundList* roundListCreate() {
    RoundList *list = (RoundList*)malloc(sizeof(RoundList));
    list->p = -1;
    return list;
}

void roundListDestroy(RoundList *l) {
    free(l);
}

void roundListInsert(RoundList *l, Point p) {
    l->p = (l->p + 1) % 8;
    l->d[l->p].x = p.x;
    l->d[l->p].y = p.y;
}

Point roundListGet(RoundList *l, int index) {
    return l->d[(l->p + 8 + index) % 8];
}

bool isCrossing(Point f1, Point t1, Point f2, Point t2) {
    printf("isCrossing: (%d,%d)->(%d,%d) and (%d,%d)->(%d,%d)\n", f1.x, f1.y, t1.x, t1.y, f2.x, f2.y, t2.x, t2.y);
    if (f1.x == t1.x) {
        // vertical 1, horizontal 2
        return (f1.x >= f2.x && f1.x <= t2.x || f1.x <= f2.x && f1.x >= t2.x) &&
               (f2.y >= f1.y && f2.y <= t1.y || f2.y <= f1.y && f2.y >= t1.y);
    } else {
        // horizontal 1, vertical 2
        return (f1.y >= f2.y && f1.y <= t2.y || f1.y <= f2.y && f1.y >= t2.y) &&
               (f2.x >= f1.x && f2.x <= t1.x || f2.x <= f1.x && f2.x >= t1.x);
    }
}

bool isSelfCrossing(int* x, int xSize){
    const int dir[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
    RoundList *list = roundListCreate();
    Point c;
    c.x = 0; c.y = 0;
    roundListInsert(list, c);
    roundListInsert(list, c);
    for (int i=0; i<xSize; i++) {
        c.x += dir[i%4][0] * x[i];
        c.y += dir[i%4][1] * x[i];
        roundListInsert(list, c);
        if (i>=2 && isCrossing(roundListGet(list, -1), roundListGet(list, 0),
                               roundListGet(list, -4), roundListGet(list, -3)))
            return true;
        if (i>=4 && isCrossing(roundListGet(list, -1), roundListGet(list, 0),
                               roundListGet(list, -6), roundListGet(list, -5)))
            return true;
    }
    for (int i=0; i<7; i++) printf("%d,%d\n", list->d[i].x, list->d[i].y);
    return false;
}



