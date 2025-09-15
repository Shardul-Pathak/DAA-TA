#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int INF = INT_MAX;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, INF);
    dist[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    cout << "Shortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    int V = 11,E;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<Edge> edges;
    cout << "Enter the edges:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int sourceNode;
    cout << "Enter the source node: ";
    cin >> sourceNode;

    bellmanFord(V, E, edges, sourceNode);
    return 0;
}
