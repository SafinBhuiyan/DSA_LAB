#include <bits/stdc++.h>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int source, int destination);
    void BFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int source, int destination) {
    adjacencyList[source].push_back(destination);
    // For an undirected graph, add the reverse edge as well
    // adjacencyList[destination].push_back(source);
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();

        for (int adjacentVertex : adjacencyList[currentVertex]) {
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                q.push(adjacentVertex);
            }
        }
    }
}

int main() {
    Graph graph(7); // Create a graph with 7 vertices

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    cout << "Breadth-First Traversal (starting from vertex 0): ";
    graph.BFS(0);

    return 0;
}
