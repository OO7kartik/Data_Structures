#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->next = NULL;
  nn->data = data;
  return nn;
}

node *getLast(node *head) {
  while(head->next) head = head->next;
  return head;
}

void add(node **head, node *nn) {
  if(!(*head)) (*head) = nn; 
  else getLast(*head)->next = nn;
}

void display(node *head) {
  while(head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}