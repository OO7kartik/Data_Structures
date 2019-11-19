#include <stdio.h>

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++)  
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
  int n1 = m-l+1;
  int n2 = r-m;

  int left[n1], right[n2];

  for(int i = 0; i < n1; i++) left[i] = arr[l+i];
  for(int i = 0; i < n2; i++) right[i] = arr[m+i+1];

  int i = 0, j = 0, k = l;
  while(i < n1 && j < n2) 
    if(left[i] <= right[j]) arr[k++] = left[i++];
    else arr[k++] = right[j++];
  while(i < n1) arr[k++] = left[i++];
  while(j < n2) arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
  if(l < r) {
    int m = (l+r)/2;

    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);

    merge(arr,l, m, r);
  }
}


int main() {
  int n = 10;
  int arr[n];
  for(int i = 0; i < n; i++)
    arr[i] = n-i;
  printArr(arr, n);
  mergeSort(arr, 0, n-1);
  printArr(arr, n);

  return 0;
}