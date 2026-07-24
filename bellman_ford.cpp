#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellman(int V, int E, vector<Edge>& edges, int s) {
    const int INF = 1e9;
    vector<int> d(V, INF);

    d[s] = 0;

    // Step 1: Relax edges V-1 times
    for(int i = 1; i < V; i++) {
        for(auto eg : edges) {
            if(d[eg.u] < INF && d[eg.u] + eg.w < d[eg.v]) {
                d[eg.v] = d[eg.u] + eg.w;
            }
        }
    }

    // Step 2: Check negative cycle
    bool hasCycle = false;
    for(auto eg : edges) {
        if(d[eg.u] < INF && d[eg.u] + eg.w < d[eg.v]) {
            hasCycle = true;
            break;
        }
    }

    // Step 3: Output
    if(hasCycle) {
        cout << "Negative Cycle Detected\n";
        return;
    }

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < V; i++) {
        if(d[i] == INF) cout << "INF ";
        else cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for(int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    bellman(V, E, edges, source);

    return 0;
}