#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

// Utility function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting Sort (for use in Radix Sort)
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Counting Sort
void countSort(int arr[], int n) {
    int max = getMax(arr, n);
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    
    free(count);
    free(output);
}

// Bucket Sort
void bucketSort(int arr[], int n) {
     int i, j, k;
    int max = arr[0];

    // Find the maximum value in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create n empty buckets
    int bucketCount = max + 1;
    int *buckets = (int *)calloc(bucketCount, sizeof(int));

    // Insert elements into their respective buckets
    for (i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Concatenate all buckets into the sorted array
    for (i = 0, j = 0; i < bucketCount; i++) {
        for (k = 0; k < buckets[i]; k++) {
            arr[j++] = i;
        }
    }

    free(buckets);
}

// Function to generate a random array
void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
       arr[i]=  n-i;
    }
}

int main() {
    srand(time(NULL));
    int sizes[] = {1000, 10000, 50000, 100000, 500000, 1000000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("Size       | BucketSort | CountSort  | RadixSort \n");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];
        int *arr1 = (int *)malloc(n * sizeof(int));
        int *arr2 = (int *)malloc(n * sizeof(int));
        int *arr3 = (int *)malloc(n * sizeof(int));
        
        generateArray(arr1, n);
        for (int i = 0; i < n; i++) arr2[i] = arr1[i];
        for (int i = 0; i < n; i++) arr3[i] = arr1[i];
        
        clock_t start, end;
        
        start = clock();
        bucketSort(arr1, n);
        end = clock();
        double bucketTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        start = clock();
        countSort(arr2, n);
        end = clock();
        double countTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        start = clock();
        radixSort(arr3, n);
        end = clock();
        double radixTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        
        printf("%-10d | %-10.6f | %-10.6f | %-10.6f\n", n, bucketTime, countTime, radixTime);
        
        free(arr1);
        free(arr2);
        free(arr3);
    }
    return 0;
}