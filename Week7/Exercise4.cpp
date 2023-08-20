#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> adjLists;
    vector<bool> visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists.resize(vertices);
    visited.resize(vertices, false);
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex) {
    queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " ";
        queue.pop();

        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.BFS(3);

    return 0;
}
