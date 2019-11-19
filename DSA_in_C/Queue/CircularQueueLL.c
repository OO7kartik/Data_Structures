#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
  int data;
  struct Queue *next;
} queue;

queue *rear = NULL;
queue *top = NULL;

int isEmpty() {
  return !top;
}

queue *getNode(int val) {
  queue *nn = (queue *) malloc (sizeof(queue));
  nn->data = val;
  nn->next =  NULL;
  return nn;
}

void enqeue(int val) {
  if(isEmpty()) {
    rear = top = getNode(val);
  }
  else {
    queue *nn = getNode(val);
    nn->next = top;
    top = nn;
  }
}

void dequeue() {
  if(top)
    top = top->next;
  else
    printf("queue empty\n");
}

void printQueue() {
  queue *itr = top;
  while(itr)
    printf("%d ", itr->data), itr = itr->next;
  printf("\n");
}

int main() {
  int n = 5;
  for(int i = 0; i < n; i++)  
    enqeue(i+1);
  printQueue();
  dequeue();
  printQueue();

  return 0;
}