#include<stdio.h>
#include<stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int arr[], int n, int key) {
    qsort(arr, n, sizeof(int), comp);
    int i=0, j = n-1;
    while (i <= j)
    {
        int mid = (i + j) >> 1;
        if(arr[mid] == key) {
            printf("Element found at %d index \n",mid);
            return mid; 
        }   else if(arr[mid] > key) {
            j = mid-1;
        }   else {
            i = mid+1;
        }
    }
    printf("Element not found \n");
    return -1;
}