#include <stdio.h>

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void bubbleSort(int arr[], int n) {
  int swapped = 0;
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
        swapped = 1;
      }
    }
    if(!swapped) return;
    swapped = 0;
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
  bubbleSort(arr, n);
  printArr(arr, n);
  return 0;
}