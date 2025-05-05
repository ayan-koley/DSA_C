#include<stdio.h>


void merge_part(int arr[], int si, int mid, int ei) {
    int k = 0;
    int result[(ei - si) + 1];
    int li = si;
    int ri = mid+1;
    while(li <= mid && ri <= ei) {
        if(arr[li] < arr[ri]) {
            result[k++] = arr[li];
            li++;
        }   else {
            result[k++] = arr[ri];
            ri++;
        }
    }
    while(li <= mid) {
        result[k++] = arr[li++];
    }
    while(ri <= ei) {
        result[k++] = arr[ri++];
    }
    k = 0;
    int li = si;
    while(k <= (ei - si)) {
        arr[li++] = result[k++];
    }   
}


void divide_part_of_marge_sort(int arr[], int si, int ei) {
    if(si >= ei) {
        return;
    }
    int mid = (si + ei) >> 1;
    divide_part_of_marge_sort(arr, si, mid);
    divide_part_of_marge_sort(arr, mid+1, ei);

    merge_part(arr, si, mid, ei);
}
int main() {
    int arr[] = {5, 4, 3, 2, 1};
    divide_part_of_marge_sort(arr, 0, 4);
    for(int i=0; i < 5; i++) {
        printf(" %d ", arr[i]);
    }
}