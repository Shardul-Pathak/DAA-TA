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

    for (int i = 0; i < V - 1; ++i) {
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
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    int V = 11;
    vector<Edge> edges;

    edges.push_back({0, 1, 6});
    edges.push_back({0, 2, 7});
    edges.push_back({1, 3, 5});
    edges.push_back({1, 4, -4});
    edges.push_back({2, 4, 9});
    edges.push_back({2, 5, 8});
    edges.push_back({3, 6, -2});
    edges.push_back({4, 6, 7});
    edges.push_back({4, 7, 1});
    edges.push_back({5, 7, -3});
    edges.push_back({6, 8, 4});
    edges.push_back({7, 8, 2});
    edges.push_back({7, 9, 3});
    edges.push_back({8, 10, 5});
    edges.push_back({9, 10, -1});

    int E = edges.size();
    int source_node = 0;

    bellmanFord(V, E, edges, source_node);

    return 0;
}