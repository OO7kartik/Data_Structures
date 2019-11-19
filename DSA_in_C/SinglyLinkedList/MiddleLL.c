#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node *head = NULL;

void printMid() {
  if(!head) {
    printf("list empty\n");
    return;
  }
  node *mid = head, *end = head;
  while (end && end->next) 
  {
    mid = mid->next;
    end = end->next->next;
  }
  printf("%d", mid->data);
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

  display(head);
  printMid();

  fclose(output);
  fclose(input);
  return 0;
}