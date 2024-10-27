#include<stdio.h>
#include<limits.h>

int myAtoi(char* s) {
    int result = 0;
    int sign = 1;
    int i = 0;


    while(s[i] == ' '){
        i++;
    }

    if(s[i] == '0' && (s[i+1] < '0' || s[i+1] > '9')){
        return 0;
    }

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    while (s[i] != '\0') {
        char sym = s[i];
        if (sym< '0' || sym> '9') {
            return result;
        }
        if (result > (INT_MAX - (sym- '0')) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (sym- '0');
        i++;
    }

    return result * sign;
 }

int main(){
    printf("%d", myAtoi("  -0012a42"));
}