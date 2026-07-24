#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V, vector<pair<int,int>> adj[], int s) {
    const int INF = 1e9;
    vector<int> d(V, INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        for(auto [v, w] : adj[u]) {
            if(d[v] > dist + w) {
                d[v] = dist + w;
                pq.push({d[v], v});
            }
        }
    }

    for(int i = 0; i < V; i++)
        cout << (d[i] == INF ? -1 : d[i]) << " ";
}
int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> adj[V];

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // For undirected graph, also add reverse edge
        // adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    dijkstra(V, adj, source);
}