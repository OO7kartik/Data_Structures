#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} node;

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->data = data;
  nn->next = NULL;
  return nn;
}

void printList(node *head) {
  while(head) 
    printf("%d ", head->data), head=head->next;
  printf("\n");
}

node *getLast(node *head) {
  while(head->next) 
    head = head->next;
  return head;
}

void getNthNodeFromEndRecur(node *head, int n) {
  int static count = 0;
  if(head) getNthNodeFromEndRecur(head->next, n);
  if(count++ == n) printf("%d \n", head->data);
}

void getNthNodeFromEnd2Ptr(node *head, int n) {
  int i = 0;
  node *ptr1 = head;
  node *ptr2 = head;
  while( i++ < n && ptr2) {
    ptr2 = ptr2->next;
  }
  while(ptr2) {
    ptr2 = ptr2->next;
    ptr1 = ptr1->next;
  }
  printf("%d \n", ptr1->data);
}

int getNthNode(node *head, int n) {
  int pos = n;
  while(--n && head) {
    head = head->next;
  }
  if(head) return head->data;
  printf("can't retrieve %d th node\n", pos);
  return -1;
}

void insertEnd(node **head, int data) {
  if(!*head) *head = getNode(data);
  else getLast(*head)->next = getNode(data);
}

void insertFront(node **head, int data) {
  node *nn = getNode(data);
  nn->next = *head;
  *head = nn;
}

void insertAfter(node **head, int data, int new_data) {
  node *itr = *head;
  if(head && (*head)->data == data) {
    (*head)->next = getNode(new_data);
    return;
  }
  while(itr) {
    if(itr->data == data) {
      node *nn = getNode(new_data);
      nn->next = itr->next;
      itr->next = nn;
      return;
    }
    itr = itr->next;
  }
}

void deleteKey(node **head, int key) {
  node *itr = *head;
  if(!(*head)) return;
  if((*head)->data == key) {
    (*head) = (*head)->next;
    return;
  }
  while(itr->next) {
    if(itr->next->data == key) {
      node *toDel = itr->next;
      itr->next = toDel->next;
      free(toDel);
      return;
    }
    itr = itr->next;
  }
}

int getListLength(node *head) {
  int listLength = 0;
  while(head) {
    listLength++;
    head = head->next;
  }
  return listLength;
}

int getListLengthRecur(node *head) {
  if(!head) return 0;
  return 1 + getListLengthRecur(head->next);
}

void printMiddleElement(node *head) {
  node *leader = head;
  node *mid = head;
  while(leader && leader->next) {
    leader = leader->next->next;
    mid = mid->next;
  }
  printf("mid: %d \n", mid->data);
}

int main() {  
  freopen("in.txt", "r", stdin);

  int n = 10;
  node *head = NULL;

  for(int i=1; i <= n; ++i) 
    insertEnd(&head, i);

  printList(head);
  printMiddleElement(head);

  return 0;
}
