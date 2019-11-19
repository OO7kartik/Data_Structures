#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node *next;
} node;

node *stack = NULL;

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->next = NULL;
  nn->data = data;
  return nn;
}

void push(char data) {
  if(!stack) 
    stack = getNode(data);
  else {
    node *temp = getNode(data);
    temp->next = stack;
    stack = temp;
  }
} 

void pop() {
  stack = stack->next;
}

int prec(char a) {
  if(a == '^')
    return 3;
  if(a == '*' || a == '/')
    return 2;
  if(a == '+' || a == '-')
    return 1;
  return 0;
}

char *inToPost(char *infix) {
  int n = strlen(infix);
  char *postfix = (char *) malloc (n);
  memset(postfix, '\0', n);

  int pf = 0;
  for(int i = 0; i < n; i++) {
    if(!prec(infix[i])) {
      if(infix[i] = '(') {
        push(infix[i]);
      } else if(infix[i] == ')') {
         while(stack && stack->data != '(') {
          postfix[pf++] = stack->data;
          pop();
      }
      pop();
    } else {
        while(stack && stack->data != '(' && prec(stack->data) >= prec(infix[i])) {
        postfix[pf++] = stack->data;
        pop();
      }
        push(infix[i]);
      }
    }else {
      postfix[pf++] = infix[i];
    }
  }

  while(!stack) {
    postfix[pf++] = stack->data;
    pop();
  }
  return postfix;
}

void printStack() {
  node *itr = stack;
  while(itr) {
    printf("%d ", itr->data);
    itr = itr->next;
  }
  printf("\n");
}

int main(){
  char *infix = "((A*B)+(C/D))";
  printf("%s", inToPost(infix));

  return 0;
}