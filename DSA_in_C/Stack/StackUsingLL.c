#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node *stack = NULL;

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->data = data;
  nn->next = NULL;
  return nn;
}

void push(int data) {
  if(!stack) stack = getNode(data);
  else {
    node *nn = getNode(data);
    nn->next = stack;
    stack = nn;
  }
}

void printStack() {
  node *itr = stack;
  while(itr) {
    printf("%d ", itr->data);
    itr = itr->next;
  }
  printf("\n");
}

void pop() {
  if(!stack) 
    printf("Stack underflow");
  else {
    node *toDel = stack;
    stack = toDel->next;
    printf("Deleted: %d\n", toDel->data);
    free(toDel);
  }
}

int main() {

  int n = 5;
  for(int i = 0; i < n; i++) 
    push(i+1);

  printStack();
  pop();
  printStack();
  
  return 0;
}