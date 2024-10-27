#include<stdio.h>
#include<string.h>

int isRepeated(int i, int j, char *s){
    int a = i;
    while(a<j){
        char x = s[a], y = s[j];
        if(x == y){
            return 1;
        }
        a++;
    }
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if(len == 0 || len == 1){
        return len;
    }
    int maxSubStr = 0;
    int i=0, j=0;
    while(j<len){ 
        if(!isRepeated(i,j,s)){
            j++;
            if(j-i>maxSubStr){
                maxSubStr = j-i;
            }
        }else{            
            i++;
        }
    }

    return maxSubStr;
}  


int main(){
    char *x = "abcabcbb";
    printf("%d", lengthOfLongestSubstring(x));
}