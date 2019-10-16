#pragma once
typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
} node;

int max(int a, int b);
int height(node *n);
node *newNode(int key);
int getBalance(node *n);
void preorder(node *root);
node *rightRotate(node *y);
node *leftRotate(node *x);
node *insert(node *root, int key);
