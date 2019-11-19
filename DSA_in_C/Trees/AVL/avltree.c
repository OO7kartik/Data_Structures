#include <stdio.h>
#include <stdlib.h>

#include "avltree.h"

int max(int a, int b) {return (a > b) ? a : b;}

int height(node *n) {
  if(!n) return 0;
  return n->height;
}

node *newNode(int key) {
  node *nn = (node*) malloc (sizeof(node));
  nn->key = key;
  nn->left = NULL;
  nn->right = NULL;
  nn->height = 1;
  return nn;
}

int getBalance(node *n) {
  if(n==NULL) return 0;
  return height(n->left)-height(n->right);
}

void preorder(node *root) {
  if(root) {
    preorder(root->left);
    printf("%d ", root->key);
    preorder(root->right);
  }
}

node *rightRotate(node *y) {
  node *x = y->left;
  node *t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height=1+max(height(y->left), height(y->right));
  x->height=1+max(height(x->left), height(x->right));

  return x;
}

node *leftRotate(node *x) {
  node *y = x->right;
  node *t2 = y->left;

  y->left = x;
  x->right = t2;

  y->height=1+max(height(y->left), height(y->right));
  x->height=1+max(height(x->left), height(x->right));

  return y; 
}

node *insert(node *root, int key) {
  if(root == NULL) return newNode(key);
  if(key < root->key) root->left = insert(root->left, key);
  else if(key > root->key) root->right = insert(root->right, key);
  else return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  if(balance > 1 && key < root->left->key) return rightRotate(root);
  if(balance < -1 && key > root->right->key) return leftRotate(root);
  if(balance > 1 && key > root->left->key) return root->left=leftRotate(root->left), rightRotate(root);
  if(balance < -1 && key < root->right->key) return root->right=rightRotate(root->right), leftRotate(root);

  return root;
}