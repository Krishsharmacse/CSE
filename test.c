#include <stdio.h>
#include <string.h>

// #define MAX_CHAR 256

// int longestUniqueSubstring(char *str) {
//     int n = strlen(str);
    
//     int lastIndex[MAX_CHAR];
//     for (int i = 0; i < MAX_CHAR; i++) {
//         lastIndex[i] = -1;
//     }
    
//     int maxLength = 0; 
//     int start = 0;     

//     for (int end = 0; end < n; end++) {
//         int charAscii = (int)str[end];
//         if (lastIndex[charAscii] >= start) {
//             start = lastIndex[charAscii] + 1;
//         }

//         lastIndex[charAscii] = end;

//         int currentLength = end - start + 1;
//         if (currentLength > maxLength) {
//             maxLength = currentLength;
//         }
//     }

//     return maxLength;
// }

// int main() {
//     char str[] = "abcabcbb";
//     int length = longestUniqueSubstring(str);
//     printf("%d", length);
//     return 0;
// }

// C program to illustrate Call by Reference
#include <stdio.h>
#include<limits.h>

// Defining a structure to represent a person
// typedef struct Person {
//     char name[50];
//     int age;
//     float height;
// } Person;

// int main() {
//     // Declaring a structure variable of type Person
//     Person p1;

//     // Assigning values to the members of the structure
//     strcpy(p1.name, "John Doe");  // Using strcpy() to assign a string
//     p1.age = 30;
//     p1.height = 5.9;

//     // Accessing and printing the structure members
//     printf("Name: %s\n", p1.name);
//     printf("Age: %d\n", p1.age);
//     printf("Height: %.1f\n", p1.height);

//     return 0;
// }


// int reverse(int x){
//     int res = 0;
//     while(x > 0){
//         res = 10*res + x%10;
//         x = x/10;
//     }

// }


int reverse(int x) {
    int res = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && pop > 7)) return 0;
        if (res < INT_MIN / 10 || (res == INT_MIN / 10 && pop < -8)) return 0;

        res = res * 10 + pop;
    }

    return res;
}

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

int main(){
    // printf("%d", reverse(-123));
    char *s = "IX";
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

    printf("%d", res);

    return 0;
}