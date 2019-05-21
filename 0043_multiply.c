// Author: xhdhr10000
// Date: 2019-05-16
char * multiply(char * num1, char * num2){
    if (num1[0] == '0' || num2[0] == '0') return "0";
    int len1 = strlen(num1), len2 = strlen(num2), len = len1+len2;
    char *ret = (char*)malloc(sizeof(char)*(len+1));
    memset(ret, 0, sizeof(char)*(len+1));
    for (int i=0; i<len1; i++) {
        for (int j=0; j<len2; j++) {
            int x = (num1[i]-'0') * (num2[j]-'0');
            int p = len-1 - (len1-i-1) - (len2-j-1);
            ret[p] += x % 10;
            ret[p-1] += x / 10;
            while (p>0 && ret[p] >= 10) {
                ret[p-1] += ret[p] / 10;
                ret[p] %= 10;
                p--;
            }
        }
    }
    for (int i=len-1; i>0; i--) {
        if (ret[i] >= 10) {
            ret[i-1] += ret[i] / 10;
            ret[i] %= 10;
        }
    }
    if (ret[0] == 0) {
        for (int i=0; i<len-1; i++) ret[i] = ret[i+1] + '0';
        ret[len-1] = 0;
    } else {
        for (int i=0; i<len; i++) ret[i] += '0';
    }
    return ret;
}



