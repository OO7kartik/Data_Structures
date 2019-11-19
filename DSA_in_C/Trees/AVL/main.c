#include <stdio.h>
#include <stdlib.h>

#include "avltree.h"


int main() {
  int n, val;
  scanf("%d", &n);

  node *root = NULL;

  for(int i = 0; i < n; i++) {
    scanf("%d", &val);
    root = insert(root, val);
  }
  preorder(root);

  return 0;
}