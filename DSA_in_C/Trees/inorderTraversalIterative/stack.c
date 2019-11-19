#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "tree.h"

node *getNode(tree *c)
{
  node *nn = (node *)malloc(sizeof(node));
  nn->next = NULL;
  nn->top = c;
  return nn;
}

int isempty(node *st)
{
  if (st == NULL)
    return 1;
  return 0;
}

void push(tree *adr, node **st)
{
  node *nn = getNode(adr);
  nn->next = (*st);
  (*st) = nn;
}

tree *pop(node **st)
{
  if (isempty(*st))
  {
    printf("Stack empty can't pop");
  }
  node *temp = (*st);
  tree *toReturn = temp->top;
  (*st) = (*st)->next;
  free(temp);
  return toReturn;
}

void display(node *st)
{
  while (!isempty(st))
  {
    printf("%c ", st->top);
    st = st->next;
  }
  printf("\n");
}
