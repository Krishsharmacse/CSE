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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int n)
{
    // Implementing a simple bubble sort for sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int x = arr[j], y = arr[j+1];
            if (x > y)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main(){
    int arr[] = {5,3,6,8};
    sort(arr,4);

    for(int i = 0; i< 4; i++){
        printf("%d ",arr[i]);
    }
}