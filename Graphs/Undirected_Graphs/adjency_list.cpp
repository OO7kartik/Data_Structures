#include <iostream>
#include<vector>
using namespace std;

//vector containing heads
void addEdge(vector<int> adj[], int v, int u)
{
	adj[u].push_back(v); //push value v to index u thereby indicating that the uth node has a connection with the vth node
	adj[v].push_back(u);
}

//to print the grap
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v]) //automatically prints all values in the first list (ie prints the first list)
           cout << "-> " << x;
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
	int V = 5;
    vector<int> adj[V]; //this is a vector of vectors (like 2D vector) but not 2D its works same as a link list :0
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
	return 0;
}