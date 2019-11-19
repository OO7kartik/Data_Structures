#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct List {
  struct List *next;
  node *down;
}List;

List *getListNode(node *head) {
  List *nn = (List *) malloc (sizeof(List));
  nn->next = NULL;
  nn->down = head;
  return nn;
}

List *list = NULL;
node *head = NULL;

int main() {
  FILE *output = freopen("out.txt", "w", stdout);
  FILE *input = freopen("in.txt", "r", stdin);

  int nnext, ndown, data;
  scanf("%d", nnext);

  for(int i = 0; i < nnext; i++) {
    if(i == 0) {
      head = NULL;
      if(!list) {
        list = getListNode(head);
      }
      else {
        list->next = getListNode(head);
      }
    }
    scanf("%d", &ndown);
    for(int j = 0; j < ndown; j++) {
      scanf("%d", &data);
      add(&head, getNode(data));
    }
  }

  fclose(output);
  fclose(input);
  return 0;

  return 0;
}