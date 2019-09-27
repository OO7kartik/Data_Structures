#include <stdio.h>
#include <stdarg.h>

#include "tree.h"
#include "stack.h"

void printstack(node *stack)
{
  printf("stack: ");
  while (!isempty(stack))
  {
    printf("%p ", stack->top->data);
  }
  printf("\n");
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

  printf("inorder: ");
  inorder(root);
  printf("\n");

  printf("preorder: ");
  preorder(root);
  printf("\n");

  printf("postorder: ");
  postorder(root);
  printf("\n");

  // fclose(output);
  // fclose(input);
  return 0;
}