#include <stdio.h>
#include <queue>

using namespace std;

int adjMatrix[10][10];
int vis[10];

void displayMatrix(int adjMatrix[10][10]) {
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }
}

void bfsUtil(int cur) {
  vis[cur] = 1;
  printf("%d ", cur);
  queue<int> q;
  q.push(cur);
  while(q.size()) {
    if(!vis[q.front()])
      bfsUtil(q.front());
    q.pop();
  }
}

void bfs() {
  for(int i = 0; i < 10; i++) {
    if(!vis[i])
    bfsUtil(i);
  }
}

int main() {
  freopen("in.txt", "r", stdin);

  int n, v, w;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v, &w);
    v--;
    w--;
    adjMatrix[v][w] = adjMatrix[w][v] = 1;
  }

  // displayMatrix(adjMatrix);
  bfs(); printf("\n");
  // displayMatrix(adjMatrix);
  return 0;
}