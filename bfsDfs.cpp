#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int vertices;                     // Number of vertices
    vector<vector<int>> adjList;      // Adjacency list representation

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add edge (for undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Depth First Search (DFS) using recursion
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    // DFS traversal from a given start vertex
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Breadth First Search (BFS)
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adjList[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }

    // Display adjacency list
    void displayGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; ++i) {
            cout << i << " -> ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayGraph();

    int start;
    cout << "\nEnter starting vertex for traversal: ";
    cin >> start;

    g.DFS(start);
    g.BFS(start);

    return 0;
}
