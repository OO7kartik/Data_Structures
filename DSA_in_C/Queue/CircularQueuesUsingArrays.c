#include <stdio.h>

#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int rear = 0;
int top = 0;

int isEmpty() {
  return top != rear;
}

void enqeue(int val) {
  if((rear+1)%QUEUE_SIZE == top)  
    printf("cant enqueue, Queue full");
  else
    queue[rear++] = val;
}

void dequeue() {
  if(top == rear)
    printf("queue is empty");
  else 
    top = (top+1)%QUEUE_SIZE;
}

void printQueue() {
  int start = top;
  while((start)%QUEUE_SIZE != rear) 
    printf("%d ", queue[start++]);
  printf("\n");
}

int main() {
  freopen("in.txt", "r", stdin);

  int n;
  scanf("%d", &n);
  printf("%d\n", n);
  for(int i = 0; i < n; i++)  
    enqeue(i+1);
  printQueue();
  dequeue();
  printQueue();

  return 0;
}