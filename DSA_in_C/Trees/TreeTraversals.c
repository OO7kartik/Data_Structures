#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
  int data;
  struct Tree *left, *right;
} tree;

tree *getNode(int data) {
  tree *nn = (tree *) malloc (sizeof(tree));
  nn->data = data;
  nn->right = nn->left = NULL;
  return nn;
}

tree *insert(tree *root, int data) {
  if(!root) {
    return getNode(data);
  } else if(root->data < data) {
    root->right = insert(root->right, data);
  } else {
    root->left = insert(root->left, data);
  }
  return root;
}

void inorder(tree *root) {
  if(root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(tree *root) {
  if(root) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(tree *root) {
  if(root) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  tree *root = NULL;

  int n, val;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &val);
    root = insert(root, val);
  }

  //using binary search tree.
  //for an input of 2 1 4 3 5
  //           2
  //         /  \
  //        1    3 
  //            / \
  //           4   5 

  // inorder: 1 2 3 4 5
  // preorder: 2 1 4 3 5
  // postorder: 1 3 5 4 2


  printf("inorder: ");
  inorder(root);
  printf("\n");

  printf("preorder: ");
  preorder(root);
  printf("\n");

  printf("postorder: ");
  postorder(root);
  printf("\n");

  return 0;
}