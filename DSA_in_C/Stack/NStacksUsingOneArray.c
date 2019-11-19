#include <stdio.h>

#define n 20
#define k 3

int arr[n];
int top[k];
int next[n];
int free = 0;

int isEmpty(int stackNumber) {
  return top[stackNumber] == -1;
}

int isFull() {
  return free == -1;
}

void init() {
  for(int i = 0; i < k; i++) 
    top[i] = -1;
  for(int i = 0; i < n-1; i++)
    next[i] = i+1;
  next[n-1] = -1; //indication end of free
}

void push(int item, int stackNumber) {
  if(isFull()) {
    printf("StackOverflow\n");
    return;
  }
 
  int i = free;                   //store index of first free slot
  free = next[i];                 //set free to next free slot
  
  next[i] = top[stackNumber];     //set this free slot to the val needed to be pushed in stack

  arr[i] = item;
}

int pop(int stackNumber) {
  if(isEmpty(stackNumber)) {
    printf("stack Underflow");
    return 9999999;
  }

  int i = top[stackNumber]; //find index of top item in stack

  top[stackNumber] = next[i];
  next[i] = free;
  free = i;

  return arr[i];
}

int main() {

  init();

  return 0;
}