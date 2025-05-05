#include<stdio.h>

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int sort_array(int arr[], int si, int ei) {
    int pivot = arr[ei];  
    int x = si - 1;
    for (int y = si; y < ei; y++) {
        if (arr[y] <= pivot) {
            x++;
            swap(arr, x, y);
        }
    }
    swap(arr, x + 1, ei); 
    return x + 1;
}


void quick_sort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }
    int partition = sort_array(arr, si, ei);
    quick_sort(arr, si, partition - 1);
    quick_sort(arr, partition + 1, ei);
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    quick_sort(arr, 0, 4);
    for(int i=0; i < 5; i++) {
        printf(" %d ", arr[i]);
    }
}