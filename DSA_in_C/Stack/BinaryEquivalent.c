#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

node *st = NULL;

void toBinary(int n) {
  while(n) {
    push(getNode(n%2), &st);
    n/=2;
  }
  while(!isempty(st)) {
    printf("%d", st->top);
    pop(&st);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  toBinary(n);

  return 0;
}