#include <stdio.h>
#include <string.h>

int graph[10][10];

void dfsUtil(int graph[10][10], int vis[], int x) {
  if(vis[x]) return;
  printf("%d ", x+1);
  vis[x] = 1;

  for(int i = 0; i < 10; i++) {
    if(graph[x][i]) {
      dfsUtil(graph, vis, i);
    }
  }
} 

void dfs(int graph[10][10]) {
  int vis[10];
  for(int i = 0; i < 10; i++)
    vis[i] = 0;

  for(int i = 0; i < 10; i++) 
    if(!vis[i]) 
      dfsUtil(graph, vis, i);
}

void printGraph(int graph[10][10]) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(graph[i][j])
        printf("%d %d\n", i+1, j+1);
    }
  }
}

int main() {
  freopen("in.txt", "r", stdin);

  for(int i = 0; i < 10; i++) 
    for(int j = 0; j < 10; j++)  
      graph[i][j] = 0;

  int n, w, v;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v, &w);
    w--;
    v--;
    graph[w][v] = graph[v][w] = 1;
  }

  dfs(graph);

  return 0;
}