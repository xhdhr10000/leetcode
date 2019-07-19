// Author: xhdhr10000
// Date: 2019-07-17
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
int maxProfit(int* prices, int pricesSize){
    int max = 0;
    int c = 0x7fffffff;
    for (int i=0; i<pricesSize; i++) {
        max = MAX(max, prices[i]-c);
        c = MIN(c, prices[i]);
    }
    return max;
}
