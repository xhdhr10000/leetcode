// Author: xhdhr10000
// Date: 2019-07-29
typedef struct {
    char *key;
    double value;
    int index;
    int prev;
} Map;

int mapGet(Map *map, int size, char *key) {
    for (int i=0; i<size; i++)
        if (!strcmp(map[i].key, key)) return i;
    return -1;
}

int setGet(Map *map, int i) {
    while (i != map[i].prev) i = map[i].prev;
    return i;
}

void setMerge(Map *map, int i, int j) {
    i = setGet(map, i);
    j = setGet(map, j);
    map[j].prev = i;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    Map *map = (Map*)malloc(sizeof(Map)*equationsSize*2);
    int pm = 0;
    
    srand(clock());
    for (int i=0; i<equationsSize; i++) {
        int a = mapGet(map, pm, equations[i][0]), b = mapGet(map, pm, equations[i][1]);
        if (a<0 && b<0) {
            double y = abs(rand()) % 100;
            double x = y * values[i];
            map[pm].key = equations[i][0];
            map[pm].value = x;
            map[pm].index = i;
            map[pm].prev = pm;
            pm++;
            map[pm].key = equations[i][1];
            map[pm].value = y;
            map[pm].index = i;
            map[pm].prev = pm-1;
            pm++;
        } else if (a>=0 && b>=0) {
            int j = i, f = -1;
            setMerge(map, a, b);
            while (abs(map[a].value/map[b].value - values[j]) > 0.000001) {
                if (f == b || map[a].index < map[b].index) {
                    map[a].value = map[b].value * values[j];
                    f = a;
                    j = map[a].index;
                    a = mapGet(map, pm, equations[j][0]);
                    b = mapGet(map, pm, equations[j][1]);
                } else {
                    map[b].value = map[a].value / values[j];
                    f = b;
                    j = map[b].index;
                    a = mapGet(map, pm, equations[j][0]);
                    b = mapGet(map, pm, equations[j][1]);
                }
            }
        } else if (a<0) {
            double x = map[b].value * values[i];
            map[pm].key = equations[i][0];
            map[pm].value = x;
            map[pm].index = i;
            map[pm].prev = b;
            pm++;
        } else {
            double y = map[a].value / values[i];
            map[pm].key = equations[i][1];
            map[pm].value = y;
            map[pm].index = i;
            map[pm].prev = a;
            pm++;
        }
    }
    
    double *ret = (double*)malloc(sizeof(double)*queriesSize);
    *returnSize = queriesSize;
    for (int i=0; i<queriesSize; i++) {
        int a = mapGet(map, pm, queries[i][0]), b = mapGet(map, pm, queries[i][1]);
        if (a<0 || b<0 || setGet(map, a) != setGet(map, b)) ret[i] = -1.0;
        else ret[i] = map[a].value / map[b].value;
    }
    
    return ret;
}
