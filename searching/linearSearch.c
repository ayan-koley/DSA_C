#include<stdio.h>
int linearSearch(int arr[], int n, int key) {
    for(int i=0; i < n; i++) {
        if(arr[i] == key) {
            printf("key found at %d index", i);
            return i;
        }
    }
    printf("Key not found");
    return -1;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    linearSearch(arr, n, key);

    return 0;
}