#include <stdio.h>
#include <stdlib.h>

#define n 10

typedef struct Node {
  int index;
  struct Node *next;
} node;

node *list[n];
node *top = NULL;
node *rear = NULL;

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->next = NULL;
  nn->index = data;
  return nn;
}

void push(int data) {
  if(!top) {
    rear = top = getNode(data);
  } else {
    node *temp = getNode(data);
    rear->next = temp;
    rear = temp;
  }
}

int pop() {
  node *toDel = top;
  int toReturn = toDel->index;
  top = top->next;
  free(toDel);
  return toReturn;
}

int isEmpty() {
  return !top;
}

void printQueue() {
  node *itr = top;
  while(itr) {
    printf("%d ", itr->index);
    itr = itr->next;
  }
  printf("\n");
}

void insert(int v, int w) {
  if(!list[v]) list[v] = getNode(w);
  else {
    node *itr = list[v];
    while(itr->next) itr = itr->next;
    itr->next = getNode(w);
  }
}


void printList() {
  for(int i = 0; i < n; i++) {
    printf("%d: ", i+1);
    node *itr = list[i];
    while(itr) {
      printf("%d ", itr->index+1);
      itr = itr->next;
    }
    printf("\n");
  }
}

void bfsUtil(int vis[], int x) {
  push(x);
  vis[x] = 1;
  while(!isEmpty()) {
    int cur = pop();
    printf("%d ", cur+1);

    node *itr = list[cur];
    while(itr) {
      if(!vis[itr->index]) {
        push(itr->index);
        vis[itr->index] = 1;
      }
      itr = itr->next;
    }
  }
}

void bfs() {
  int vis[n];
  for(int i = 0; i < n; i++)
    vis[i] = 0;
  
  for(int i = 0; i < n; i++)
    if(!vis[i])
      bfsUtil(vis, i);
}

int main() {
  freopen("in.txt", "r", stdin);

  int v, w;

  for(int i = 0; i < n; i++) 
    list[i] = NULL;

  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v, &w);
    w--;
    v--;
    insert(w, v);
    insert(v, w);
  }

  bfs();

  return 0;
}