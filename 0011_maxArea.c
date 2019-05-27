// Author: xhdhr10000
// Date: 2019-05-27
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int maxArea(int* height, int heightSize){
    int max = 0;
    int *prev = (int*)malloc(sizeof(int)*heightSize);
    prev[0] = 0;
    for (int i=1; i<heightSize; i++) {
        int j = prev[i-1];
        while (j >= 0) {
            max = MAX(max, MIN(height[j], height[i])*(i-j));
            j = j>0 ? prev[j-1] : -1;
        }
        if (height[i] > height[prev[i-1]]) prev[i] = i;
        else prev[i] = prev[i-1];
    }
    free(prev);
    return max;
}



