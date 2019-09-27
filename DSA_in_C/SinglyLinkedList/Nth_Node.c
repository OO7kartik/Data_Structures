#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node *head = NULL;

node *nthNode(int nth) {
  node *itr = head;
  while(--nth) {
    itr = itr->next;
  }
  return itr;
}

int main() {
  FILE *output = freopen("out.txt", "w", stdout);
  FILE *input = freopen("in.txt", "r", stdin);

  int n, nth, data;
  scanf("%d%d", &n, &nth);

  for(int i = 0; i < n; i++) {
    scanf("%d", &data);
    add(&head, getNode(data));
  }

  display(head);
  printf("%d\n", *nthNode(nth));

  fclose(output);
  fclose(input);
  return 0;

  return 0;
}