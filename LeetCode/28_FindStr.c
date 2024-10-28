#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool checkStr(char* str1, char * target, int targetLength, int start){
    int j = 0;
    while(j < targetLength){
        char a = str1[start], b = target[j];
        if(a != b){
            return false;
        }
        j++;
        start++;
    }

    return true;
}

int strStr(char* haystack, char* needle) {
    int needleLength = strlen(needle);
    int haystackLength = strlen(haystack);
    
    int i = 0;
    while(i < haystackLength){
        if(checkStr(haystack, needle, needleLength, i)){
            return i;
        }else{
            i++;
        }
    }

    return -1;
}

int main(){
    char *haystack = "mississippi", *needle = "issip";
    printf("%d", strStr(haystack, needle));

}