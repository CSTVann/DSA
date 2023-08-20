#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int v, w;
};

class Graph
{
    public:

        vector<vector<int>> adjList;

        Graph(vector<Edge> const &edges, int n)
        {
            adjList.resize(n);

            for (auto &edges: edges)
            {
                adjList[edges.v].push_back(edges.w);

                // adjList[edges.w].push_back(edges.v);
            }
        }
};

void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int v: graph.adjList[i]) {
            cout << v << " -> ";
        }
        cout<<endl;
    }
    cout << endl;
}

int main()
{
    vector<Edge> edges = 
    {
        {0, 1}, {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };

    int n = 4;

    Graph graph(edges, n);

    printGraph(graph, n);
}