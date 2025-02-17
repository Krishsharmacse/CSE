#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* removeStars(char* s) {
    int len = strlen(s);
    char *newStr = (char*)malloc(sizeof(char) * len);
    int chr=0, stars = 0;
    int i=0, index = 0;
    while(i<len){
        if(s[i] != '*'){
            newStr[index++] = s[i];
        }else{
            index--;
        }
        i++;
    }

    newStr[index]='\0';

    return newStr;

}


int main(){
    char str[100] = "leet**cod*e";
    printf("%s",removeStars(str));
}