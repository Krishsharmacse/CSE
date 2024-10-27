#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int x = INT_MAX, i=1;
    if(strsSize <= 1){
        return strs[0];
    }
    
    while(i < strsSize){
        int j = 0;
        while(strs[i-1][j] != '\0' && strs[i][j] != '\0'){
            char a= strs[i][j], b =strs[i-1][j];
            if(a == b){
                j++;
            }else{
                break;
            }
            j++;
        }
        if(j == 0){
            return "";
        }
        if(j < x){
            x = j;
        }

        i++;
    }


    char *substr = (char *)malloc(x + 1);
    strncpy(substr, strs[0], x);
    substr[x] = '\0';
    return substr;
}   


int main(){
   char *x[] = {"flower","flow","flight"};


   char *y = longestCommonPrefix(x, 3);
   printf("%s\n", y);

}