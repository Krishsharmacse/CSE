#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

int longestUniqueSubstring(char *str) {
    int n = strlen(str);
    
    int lastIndex[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR; i++) {
        lastIndex[i] = -1;
    }
    
    int maxLength = 0; 
    int start = 0;     

    for (int end = 0; end < n; end++) {
        int charAscii = (int)str[end];
        if (lastIndex[charAscii] >= start) {
            start = lastIndex[charAscii] + 1;
        }

        lastIndex[charAscii] = end;

        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main() {
    char str[] = "abcabcbb";
    int length = longestUniqueSubstring(str);
    printf("%d", length);
    return 0;
}
