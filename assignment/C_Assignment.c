// 1: Write a Program to print the Fibonacci series using recursion.

#include<stdio.h>

void printFibonacciSeries(int n); 
int fibo(int n);

int main(){
    printFibonacciSeries(6);
    return 0;
}


int fibo(int n ){
    if(n <= 0 || n == 1) return n;

    return fibo(n-1) + fibo(n-2);    
}

void printFibonacciSeries(int n){
    printf("fibonacci series:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibo(i));
    }
    printf("\n");
}




// -------------------------------------------------------------


// 2: Write a Program to Reverse an Array.

#include<stdio.h>

void Reverse(int *arr, int size);
void printArray(int *arr, int size);

int main(){

    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    printArray(arr, n);
    
    Reverse(arr, n);

    printf("Reversed Array: ");
    printArray(arr, n);

    return 0; 
}

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Reverse(int *arr, int size){
    int i = 0, j = size-1;
    while(i<j){
        swap(arr, i++, j--);
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i< size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// -------------------------------------------------------------


// 3: Write a Program to find the factorial of a given number.


#include<stdio.h>

int fact(int n);

int main(){
    int n = 5;
    printf("factorial of %d is %d",n, fact(5));

    return 0;
}


int fact(int n){
    if(n == 0 || n == 1) return 1;

    return n * fact(n-1);
}



// -------------------------------------------------------------

// 4: Write a Program to search elements in an array (using Binary Search).

#include<stdio.h>

void printArray(int *arr, int size);
int binSearch(int *arr, int target, int left, int right);

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    if (binSearch(arr, target, 0, n - 1)) {
        printf("Element %d found in the array.\n", target);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

int binSearch(int *arr, int target, int left, int right){
    if(left > right){
        return 0;
    }

    int mid = (left + right) / 2;

    if(arr[mid] > target){
        return binSearch(arr, target, left, mid-1);
    }else if(arr[mid] < target){
        return binSearch(arr, target, mid+1, right);
    }else{
        return 1;
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i< size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// -------------------------------------------------------------

// 5: Write a Program to concatenate two strings.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* concat(char* s1, char* s2);

int main(){
    char s1[] = "hello ";
    char s2[] = "world";

    char* result = concat(s1, s2);
    printf("concatenated string: %s\n", result);

    return 0;
}


char* concat(char* s1, char* s2){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int length = l1+l2, index = 0;

    char* res = (char*)malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(i < l1){
        res[index++] = s1[i++];
    }

    i = 0;
    while(i < l2){
        res[index++] = s2[i++];
    }

    res[length] = '\0';


    return res;
}



// -------------------------------------------------------------

// 6: Write a Program to check if the given string is a palindrome string or not.

#include<stdio.h>
#include<string.h>

int isPalindrome(char* str);

int main(){

    char s[] = "radar";

    if(isPalindrome(s)){
        printf("stirng '%s' is a palindrome string\n", s);
    }else{
        printf("stirng %s is not a palindrome string\n", s);
    }

}

int isPalindrome(char* str){
    int i = 0;
    int j = strlen(str)-1;

    while(i < j){
        if(str[i++] != str[j--]){
            return 0;
        }
    }

    return 1;
}



// -------------------------------------------------------------

// 7:  Write a program to sort an array using Insertion Sort.

#include<stdio.h>

void insertionSort(int *arr, int n);
void printArray(int *arr, int size);

int main(){
    int arr[] = {5,7,3,1,3,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("unsorted array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("sorted array: ");
    printArray(arr, n);

    return 0;
}

void printArray(int *arr, int size){
    for(int i = 0; i< size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n){
    int i, j;

    for (i = 1; i < n; i++) {
        int temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            arr[j--] = temp;
        }
    }
}



// -------------------------------------------------------------

// 8:Write a program to sort an array using Quick Sort.

#include <stdio.h>

void swap(int* arr, int i, int j);
int pivot(int *arr, int left, int right);
void quickSort(int *arr, int left, int right);
void printArray(int arr[], int size);


int main() {
    int arr[] = {4,6,1,7,3,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array : ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);

    printf("sorted array :   ");
    printArray(arr, n);
    return 0;
}


void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int pivot(int *arr, int left, int right){
    int pivot = arr[left];
    int i = left + 1;
    
    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    
    swap(arr, left, i - 1);
    
    return i - 1;
}

void quickSort(int *arr, int left, int right){
    if(left < right){
        int index = pivot(arr, left, right);
        quickSort(arr, left, index-1);
        quickSort(arr,index + 1, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



// -------------------------------------------------------------

// 9: Write a program to store information on students using structure.

#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void displayStudentInfo(struct Student student);

int main() {
    struct Student students[3] = {
        {"abc", 601, 85.5},
        {"xyz", 602, 92.3},
        {"pqr", 603, 78.9}
    };
    
    printf("Student Information:\n");
    for (int i = 0; i < 3; i++) {
        displayStudentInfo(students[i]);
    }
    
    return 0;
}

void displayStudentInfo(struct Student student) {
    printf("\nRoll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);
}



// -------------------------------------------------------------

// 10:  Write a Program to calculate Compound Interest

#include <stdio.h>
#include <math.h>

float CI(float principal, float rate, int time);

int main() {
    float principal = 1000.0;  
    float rate = 5.0;
    int time = 3;               


    float amount = CI(principal, rate, time);
    float compoundInterest = amount - principal;

    printf("Principal: %.2f\n", principal);
    printf("Annual Interest Rate: %.2f%%\n", rate);
    printf("Time (in years): %d\n", time);
    printf("The compound interest is: %.2f\n", compoundInterest);
    printf("The total amount (Principal + Interest) is: %.2f\n", amount);

    return 0;
}


float CI(float principal, float rate, int time) {
    return principal * pow(1 + rate / 100, time);
}
