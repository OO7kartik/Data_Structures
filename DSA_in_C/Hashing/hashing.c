#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define multiplier 263
#define prime 1000000007
#define bucketSize 20
#define ll long long

typedef struct List {
  char *s;
  struct List *next;
} list;

list *hashMap[bucketSize]; 

int getHash(char *s) {
  int len = strlen(s);
  ll hashCode = 0;
  for(int i = 0; i < len; i++) 
    hashCode = (hashCode*multiplier+s[i])%prime;
  // printf("%s %d\n", s, hashCode % bucketSize);
  return hashCode % bucketSize;
}

list *getNode(char *s) {
  list *nn = (list *) malloc (sizeof(list));
  nn->s = s;
  nn->next = NULL;
  return nn;
}

list *getLast(list *node) {
  if(!node) return node;
  while(node->next) node = node->next;
  return node;
}

void insert(char *s) {
  int hash = getHash(s);
  if(!hashMap[hash]) hashMap[hash] = getNode(s);
  else getLast(hashMap[hash])->next = getNode(s);
}

void printHashMap() {
  printf("The hash table now: \n");
  for(int i = 0; i < bucketSize; i++) {
    printf("%d: ", i);
    list *node = hashMap[i];
    while(node) {
      printf("%s ", node->s);
      node = node->next;
    }
    printf("\n");
  }
}

int main() {
  int n = 26;
  char *items[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  char *s;
  for(int i = 1; i <= bucketSize; i++) hashMap[i] = NULL;
  for(int i = 0; i < n; i++) insert(items[i]);
  printHashMap();
  return 0;    
}