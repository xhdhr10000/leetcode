// Author: xhdhr10000
// Date: 2019-05-14
bool inline isPair(char l, char r) {
    return l=='(' && r==')' ||
           l=='{' && r=='}' ||
           l=='[' && r==']';
}

bool isValid(char * s){
    char *stack = (char*)malloc(sizeof(char)*strlen(s));
    int p = 0;
    for (int i=0; i<strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') stack[p++] = s[i];
        else if (p>0 && isPair(stack[p-1], s[i])) p--;
        else return false;
    }
    if (p != 0) return false;
    return true;
}



