#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = (int *) calloc (10, sizeof(int));
  ptr = (int*) realloc(ptr, 100*sizeof(int));
  return 0;
}