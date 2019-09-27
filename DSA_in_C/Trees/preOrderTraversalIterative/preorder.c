#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "stack.h"

void preorderIter(tree *root)
{
  node *stack = NULL;
  push(root, &stack);
  while (!isempty(stack))
  {
    // display(stack);
    printf("%d ", stack->top->data);
    node *st = pop(&stack);
    tree *adr = st->top;
    if (adr->right)
    {
      push(adr->right, &stack);
    }
    if (adr->left)
    {
      push(adr->left, &stack);
    }
    free(st);
  }
}

int main()
{
  // FILE *output = freopen("out.txt", "w", stdout);
  // FILE *input = freopen("in.txt", "r", stdin);

  tree *root = NULL;

  int n, val;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &val);
    root = insert(root, val);
  }

  printf("fake: ");
  preorder(root);
  printf("\n");

  printf("preorder: ");
  preorderIter(root);
  printf("\n");

  // fclose(output);
  // fclose(input);
  return 0;
}