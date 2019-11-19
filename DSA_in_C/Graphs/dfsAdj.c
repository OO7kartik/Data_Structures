#include <stdio.h>
#include <stdlib.h>

#define n 10

typedef struct Node {
  int data;
  struct Node *next;
} node;

node *list[n];

node *getNode(int data) {
  node *nn = (node *) malloc (sizeof(node));
  nn->next = NULL;
  nn->data = data;
  return nn;
}

void insert(int v, int w) {
  if(!list[v]) list[v] = getNode(w);
  else {
    node *itr = list[v];
    while(itr->next) itr = itr->next;
    itr->next = getNode(w);
  }
}

void init() {
  for(int i = 0; i < n; i++) 
    list[i] = NULL;
}

void printList() {
  for(int i = 0; i < n; i++) {
    node *itr = list[i];
    printf("%d: ", i+1);
    while(itr) {
      printf("%d ", itr->data+1);
      itr = itr->next;
    }
    printf("\n");
  }
}
 
void dfsUtil(int vis[], int x) {
  if(vis[x]) return;
  printf("%d ", x+1);
  vis[x] = 1;
  
  node *itr = list[x];
  while(itr) {
    if(!vis[itr->data]) 
      dfsUtil(vis, itr->data);
    itr = itr->next;
  }
}

void dfs() {
  int vis[n];
  for(int i = 0; i < n; i++) vis[i] = 0;
  for(int i = 0; i < n; i++)
    if(!vis[i])
      dfsUtil(vis, i);
}

int main() {
  freopen("in.txt", "r", stdin);
  init();

  int v, w;

  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v, &w);
    v--;
    w--;
    insert(v, w);
    insert(w, v);
  }
  
  dfs();

  return 0;
}