#include <iostream>
#include <vector>
#include <unordered_map>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (int v : adjacencyList[i]) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    TreeNode* insertRecursive(TreeNode* current, int val) {
        if (current == nullptr) {
            return new TreeNode(val);
        }

        if (val < current->data) {
            current->left = insertRecursive(current->left, val);
        } else if (val > current->data) {
            current->right = insertRecursive(current->right, val);
        }

        return current;
    }
};

int main() {
    // Graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    std::cout << "Graph:" << std::endl;
    g.printGraph();
    std::cout << std::endl;

    // Binary Search Tree
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    std::cout << "Binary Search Tree: Perform tree-related operations" << std::endl;
    std::cout << std::endl;

    // Hash Table
    std::unordered_map<std::string, int> hashTable;

    hashTable["apple"] = 5;
    hashTable["banana"] = 8;
    hashTable["grape"] = 3;

    std::cout << "Hash Table: Value of 'banana': " << hashTable["banana"] << std::endl;

    return 0;
}
