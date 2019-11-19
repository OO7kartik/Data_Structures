#include <stdio.h>
#include <stdlib.h>

#define n 10

typedef struct Node {
  int index;
  struct Node *next;
} node;

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

int list[n][n];

void printList() {
  for(int i = 0; i < n; i++) {
    printf("%d: ", i+1);
    for(int j = 0; j < n; j++) {
      if(list[i][j])
        printf("%d ", j+1);
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
    for(int i = 0; i < n; i++) {
      if(list[cur][i] && !vis[i]) {
        push(i);
        vis[i] = 1;
      }
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
    for(int j = 0; j < n; j++)
      list[i][j] = 0;

  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v, &w);
    w--;
    v--;
    list[v][w] = list[w][v] = 1;
  }

  bfs();

  return 0;
}