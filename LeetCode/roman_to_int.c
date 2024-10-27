#include<stdio.h>

int getNum(char s){
    switch(s){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
    int i=0, res = 0;
    while(s[i] != '\0'){
        int curVal = getNum(s[i]);
        int nextVal = getNum(s[i+1]);
        int val = curVal;

        if(curVal < nextVal){
            val = nextVal - curVal;
            i++;
        }

        res += val;
        i++;
    }

    return res;
}


int main(){
    printf("%d\n", romanToInt("LX"));
    printf("%d\n", romanToInt("XL"));

    return 0;
}