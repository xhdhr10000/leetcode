// Author: xhdhr10000
// Date: 2019-05-04
int countSegments(char * s){
    int count = 0;
    for (int i=1; i<strlen(s); i++) {
        if (s[i] == ' ' && s[i-1] != ' ') count++;
    }
    if (strlen(s) > 0 && s[strlen(s)-1] != ' ') count++;
    return count;
}
