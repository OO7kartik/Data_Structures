#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
  int data;
  struct Tree *left, *right; 
} tree;

typedef struct SNode {
  tree *top;
  struct SNode *next; 
} node;

node *stack = NULL;
tree *root = NULL;

node *getNode(tree *c)
{
  node *nn = (node *)malloc(sizeof(node));
  nn->next = NULL;
  nn->top = c;
  return nn;
}

void push(tree *adr, node **st)
{
  node *nn = getNode(adr);
  nn->next = (*st);
  (*st) = nn;
}

int isempty()
{
  if (stack == NULL)
    return 1;
  return 0;
}

tree *pop(node **st)
{
  if (!(*st))
  {
    printf("Stack empty can't pop");
  }
  node *temp = (*st);
  (*st) = (*st)->next;
  return temp->top;
}

tree *getTreeNode(int data)
{
  tree *nn = (tree *)malloc(sizeof(tree));
  nn->left = nn->right = NULL;
  nn->data = data;
  return nn;
}

tree *insert(tree *root, int data)
{
  if (!root)
  {
    return getTreeNode(data);
  }
  else if (root->data < data)
  {
    root->right = insert(root->right, data);
  }
  else
  {
    root->left = insert(root->left, data);
  }
  return root;
}

void inorder(tree *root)
{
  if (root)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(tree *root)
{
  if (root)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(tree *root)
{
  if (root)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void preorderIterative() {
  node *st;
  tree *cur = root;
  push(root, &st);
  while(st) {
    cur = pop(&st);
    printf("%d ", cur->data);
    if(cur->right) push(cur->right, &st);
    if(cur->left) push(cur->left, &st);
  }
}

void inorderIterative() {
  node *st = NULL;
  tree *cur = root;

  while(1) {
    if(cur) {
      push(cur, &st);
      cur = cur->left;
    } else {
      if(st) {
        cur = pop(&st);
        printf("%d ", cur->data);
        cur = cur->right;
      } else break;
    }
  }
}

void postorderIterative() {
  node *s1 = NULL;
  node *s2 = NULL;

  tree *cur;
  push(root, &s1);

  while(s1) {
    cur = pop(&s1);
    push(cur, &s2);

    if(cur->right) push(cur->right, &s1);
    if(cur->left) push(cur->left, &s1);
  }
  while(s2) {
    cur = pop(&s2);
    printf("%d ", cur->data);
  }
}

int main() {

    int n, val;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &val);
    root = insert(root, val);
  }

  printf("fake: ");
  postorder(root);
  printf("\n");

  printf("curTraversal: ");
  postorderIterative(root);
  printf("\n");

  return 0;
}