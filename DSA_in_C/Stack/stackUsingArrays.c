#include <stdio.h>

#define STACK_SIZE 100 

int stack[STACK_SIZE] = {};
int top = 0;

void push(int val) {
  if(top >= STACK_SIZE)
    printf("stack overflow\n");
  else 
    stack[top++] = val;
}

void pop() {
  if(top) top--;
  else printf("stack underflow\n");
}

void printStack() {
  for(int i = 0; i < top; i++) 
    printf("%d ", stack[i]);
  printf("\n");
}

int main() {
  freopen("in.txt", "r", stdin);

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) 
    push(i+1);
  printStack();

  return 0;
}