#include<stdio.h>
#include<limits.h>

void selectionSort(int arr[], int n) {
    for(int i=0; i < n-1; i++) {
        int minVal = INT_MAX;
        int minIdx = -1;
        for(int j=i; j < n; j++) {
            if(minVal > arr[j]) {
                minVal = arr[j];
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;

    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
