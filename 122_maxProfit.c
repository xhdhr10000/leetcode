// Author: xhdhr10000
// Date: 2019-05-14

int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0) return 0;
    int ret = 0, i = 0, j = 0;
    while (i<pricesSize-1) {
        while (j<pricesSize-1 && prices[j] <= prices[j+1]) j++;
        ret += prices[j] - prices[i];
        i = j;
        while (j<pricesSize-1 && prices[j] >= prices[j+1]) j++;
        i = j;
    }
    return ret;
}



