#ifndef linked_list
#define linekd_list

typedef struct Node {
  int data;
  struct Node *next;
}node;

node *getNode(int data);
node *getLast(node *head);
void add(node **head, node *nn);
void display(node *head);

#endif