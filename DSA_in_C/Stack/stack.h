#ifndef stack
#define stack

typedef struct Node {
  char top;
  struct Node *next;
} node;

node *getNode(int c);
void display(node *st);
int isempty(node *st);
void push(node *nn, node **st);
void pop(node **st);


#endif