#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "stack.h"
node *st = NULL;

int prec(char c) {
  if(c == '^') return 3;
  if(c == '*' || c == '/') return 2;
  if(c == '+' || c == '-') return 1;
}

int isoperator(char c) {
  if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')') return 1;
  return 0;
}

char *convert(char *infix) {
  int n = strlen(infix);
  char *postfix = (char *) malloc (n);
  memset(postfix, '\0', n);
  printf("sizeof infix: %d\n", n);

  int pf = 0;
  for(int i = 0; i < n; i++) {

    if(isoperator(infix[i])) {
      printf("this is operator\n"); 
      if(infix[i]  == '(') {
        push(getNode(infix[i]), &st);
      }
      else if(infix[i] == ')') {
        while(!isempty(st) && st->top != '(') {
          postfix[pf++] = st->top;
          pop(&st);
        }
        pop(&st);
      } else {
        printf("this op");
        while(!isempty(st) && st->top != '(' && prec(st->top) >= prec(infix[i])) {
          postfix[pf++] = st->top;
          pop(&st);
        } 
        push(getNode(infix[i]), &st);
      }
    } else {
      postfix[pf++] = infix[i];
    }
    printf("cur: %c\n", infix[i]);
    printf("postfix: %s\n", postfix);
    printf("stack: "); display(st);
    printf("\n\n\n");
  }
  while(!isempty(st)) {
    postfix[pf++] = st->top;
    pop(&st);
  }
  return postfix;
}

int main() {

  char *infix = "((A*B)+(C/D))";
  printf("%s", convert(infix));

  return 0;
}