#include <stdio.h>

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

void sortSelection(int arr[], int n) {
  for(int i = 0; i < n-1; i++) {
    int curMin = arr[i];
    for(int j = i+1; j < n; j++) {
      if(arr[j] < curMin)
        curMin = arr[j];
    }
  swap(&arr[i], &curMin);
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
  sortSelection(arr, n);
  printArr(arr, n);

  return 0;
}