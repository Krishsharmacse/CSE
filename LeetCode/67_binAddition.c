#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverseString(char* s) {
    int i = 0, j = strlen(s)-1;

    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }
}

char* addBinary(char* a, char* b) {
    int i = strlen(a)-1;
    int j = strlen(b)-1;
    int maxLength = (i > j ? i : j) + 2; 
    char* ans = (char*)malloc(maxLength * sizeof(char) + 1); 
    int carry = 0, Index = 0;
    
    while(i>=0 || j>=0 || carry){
        if(i>=0){
            int x = a[i] - '0';
            carry += x;
            i--;
        }
        if(j>=0){
            int y = b[j] - '0';
            carry += y;
            j--;
        }
        char val = (carry%2 + '0');
        ans[Index++] = val;
        carry = carry/2;
    }
    ans[Index] = '\0';
    reverseString(ans);
    return ans;
}

int main(){
    char a[] = "1010", b[] = "1011";
    char *sum = addBinary(a,b);
    printf("%s\n", sum);
}