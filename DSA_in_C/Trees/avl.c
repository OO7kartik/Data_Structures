#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
  int height;
} node;

int max(int a, int b) {
  return (a>b) ? a : b;
}

int height(node *root) {
  if(root) return root->height;
  return 0;
}

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->data = data;
  nn->left = nn->right = NULL;
  nn->height = 1;
  return nn;
}

int getBalance(node *root) {
  if(root)
    return height(root->left)-height(root->right);
  return 0;
}

node *rightRotate(node *y) {
  node *x = y->left;
  node *t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = 1+max(height(y->left), height(y->right));
  x->height = 1+max(height(x->left), height(x->right));

  return x;
}

node *leftRotate(node *x) {
  node *y = x->right;
  node *t2 = y->left;

  y->left = x;
  x->right = t2;

  x->height = 1+max(height(x->left), height(x->right));  
  y->height = 1+max(height(y->left), height(y->right));

  return y;
}

node *insert(node *root, int data) {
  if(!root) 
    return getNode(data);
  if(root->data < data)
    root->right = insert(root->right, data);
  else if(root->data > data)
    root->left = insert(root->left, data);
  else 
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  if(balance > 1 && data < root->left->data)
    return rightRotate(root);
  if(balance < -1 && data > root->right->data)
    return leftRotate(root);
  if(balance > 1 && data > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if(balance < -1 && data < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}

node *minValNode(node *root) {
  node *cur = root;
  while(cur->left != NULL)
    cur = cur->left;
  return cur;
}

node *delete(node *root, int data) {
  if(!root) 
    return root;
  if(data < root->data)
    root->left = delete(root->left, data);
  else if(data > root->data)
    root->right = delete(root->right, data);
  else { 
    if(!root->left || !root->right) { //does not have both children
      node *temp = root->left ? root->left : root->right;
      if(!temp) { //means no children
        temp = root;
        root = NULL;
      } else *root = *temp;
      free(temp);
    } else {
      node *temp = minValNode(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }

  if(!root)
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  if(balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);
  if(balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);
  if(balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if(balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preOrder(node *root) { 
  if(root != NULL) { 
    printf("%d ", root->data); 
    preOrder(root->left); 
    preOrder(root->right); 
  } 
} 

int main() {
  node *root = NULL;

	root = insert(root, 9); 
	root = insert(root, 5); 
	root = insert(root, 10); 
	root = insert(root, 0); 
	root = insert(root, 6); 
	root = insert(root, 11); 
	root = insert(root, -1); 
	root = insert(root, 1); 
	root = insert(root, 2); 

  printf("Preorder traversal of the constructed AVL tree is \n"); 
  preOrder(root);
  printf("\n");

  root = delete(root, 10); 
  root = delete(root, -1);

  printf("\nPreorder traversal after deletion of 10 \n"); 
	preOrder(root); 
  printf("\n");

  return 0;
}