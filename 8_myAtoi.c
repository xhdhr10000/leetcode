// Author: xhdhr10000
// Date: 2019-05-14
bool inline isInt(char c) {
    return c >= '0' && c <= '9';
}

int myAtoi(char * str){
    const int min = -0x80000000, max = 0x7fffffff;
    int sign = 0;
    __int64_t ret = max+1;
    for (int i=0; i<strlen(str); i++) {
        if (ret == max+1) {
            if (sign != 0 && !isInt(str[i])) return 0;
            if (!isInt(str[i]) && str[i] != '-' && str[i] != '+' && str[i] != ' ')
                return 0;
            if (str[i] == '-') {
                if (sign != 0) return 0;
                sign = -1;
            } else if (str[i] == '+') {
                if (sign != 0) return 0;
                sign = 1;
            } else if (isInt(str[i])) {
                if (sign == 0) sign = 1;
                ret = str[i] - '0';
            }
        } else {
            if (isInt(str[i])) {
                ret = ret * 10 + str[i] - '0';
                if (sign*ret < min) return min;
                if (sign*ret > max) return max;
            } else 
                return sign*ret;
        }
    }
    if (ret == max+1) ret = 0;
    return sign*ret;
}



