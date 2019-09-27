#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node *head = NULL;

void reverse() {
  node *next;
  node *prev = NULL;
  node *cur = head;
  while(cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  head = prev;
}

int main() {
  FILE *output = freopen("out.txt", "w", stdout);
  FILE *input = freopen("in.txt", "r", stdin);

  int n, data;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &data);
    add(&head, getNode(data));
  }

  printf("Given: ");  display(head);
  reverse();
  printf("Reversed: "); display(head);

  fclose(output);
  fclose(input);
  return 0;

  return 0;
}