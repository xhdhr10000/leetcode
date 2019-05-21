// Author: xhdhr10000
// Date: 2019-05-01
int countSubstringsAt(char *s, int x, int len) {
    int count = 0;
    int c = 1 - len % 2;
    while (x-len/2+c>=0 && x+len/2<strlen(s) && s[x-len/2+c]==s[x+len/2]) {
        count++;
        len += 2;
    }
    return count;
}

int countSubstrings(char * s){
    int count = strlen(s);
    for (int i=0; i<strlen(s); i++) {
        count += countSubstringsAt(s, i, 2);
        count += countSubstringsAt(s, i, 3);
    }
    return count;
}



