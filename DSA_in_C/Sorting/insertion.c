#include <stdio.h>

void sortInsertion(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];   
        int j = i-1;
        while(j >= 0 && arr[j] > key) 
            arr[j+1] = arr[j], j = j-1;
        arr[j+1] = key; 
    }
}

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++)  
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n = 10;
    int arr[n];
    for(int i = 0; i < n; i++)
        arr[i] = n-i;
    printArr(arr, n);
    sortInsertion(arr, n);
    printArr(arr, n);

    return 0;
}
