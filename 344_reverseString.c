// Author: xhdhr10000
// Date: 2019-05-14
void inline swap(char *s, int x, int y) {
    char c = s[x];
    s[x] = s[y];
    s[y] = c;
}

void reverseString(char* s, int sSize){
    int i=0, j=sSize-1;
    while (i<j) {
        swap(s, i, j);
        i++;
        j--;
    }
}



