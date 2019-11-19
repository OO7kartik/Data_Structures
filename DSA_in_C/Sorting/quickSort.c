#include <stdio.h>

void swap(int *x, int *y) {
  int t = *x; 
  *x = *y;
  *y = t;
}

void printArr(int arr[], int n) {
  for(int i = 0; i < n; i++)  
    printf("%d ", arr[i]);
  printf("\n");
}

int partition(int arr[], int l, int r) {
  int pivot = arr[l];
  int k = l;
  for(int i = l+1; i < r; i++)
    if(arr[i] < pivot)
      swap(&arr[++k], &arr[i]);
  swap(&arr[k], &arr[l]);
  return k;
}

void quickSort(int arr[], int l, int r) {
  if(l < r) {
    int pivot = partition(arr, l, r);
    quickSort(arr, l, pivot);
    quickSort(arr, pivot+1, r);
  }
}

int main() {
  int n = 10;
  int arr[n];
  for(int i = 0; i < n; i++)
    arr[i] = n-i;
  printArr(arr, n);
  quickSort(arr, 0, n);
  printArr(arr, n);

  return 0;
}