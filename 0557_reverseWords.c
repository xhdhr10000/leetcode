// Author: xhdhr10000
// Date: 2019-05-14
char * reverseWords(char * s){
    char *ret = (char*)malloc(sizeof(char)*(strlen(s)+1));
    int i=0, j=-1;
    
    while (strlen(s)>0 && s[0] == ' ') s++;
    while (strlen(s)>0 && s[strlen(s)-1] == ' ') s[strlen(s)-1] = 0;
    while (j<(int)strlen(s)) {
        j++;
        if (s[j] == ' ') {
            for (int k=i,l=j-1; k<j; k++,l--) ret[l] = s[k];
            ret[j] = s[j];
            i = j+1;
        }
    }
    if (i<j) {
        for (int k=i,l=j-1; k<j; k++,l--) ret[l] = s[k];
    }
    ret[strlen(s)] = 0;
    
    return ret;
}



