#include <iostream>
#include <vector>
using namespace std;

// To add an edge
void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt)
{
    adj[u].emplace_back(v, wt);
    adj[v].emplace_back(u, wt);
}

// Print adjacency list representation of graph
void printGraph(const vector<vector<pair<int, int>>>& adj)
{
    for (int u = 0; u < adj.size(); u++)
    {
        cout << u + 1;
        for (const auto& [v, wt] : adj[u])
        {
            cout << "\t-> \t" << v + 1 << "\tweighted: " << wt << "\n";
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 2);
    printGraph(adj);
    return 0;
}
