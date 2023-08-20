// C++ program to represent undirected and weighted graph
// using STL. The program basically prints adjacency list
// representation of graph
#include <iostream>
#include <vector>
using namespace std;

// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 1; u < V; u++)
    {
        cout << u;
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\t-> \t" << v << "\twighted:"
                 << w << "\n";
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 1, 2, 5);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 3, 4, 2);
    printGraph(adj, V);
    return 0;
}
