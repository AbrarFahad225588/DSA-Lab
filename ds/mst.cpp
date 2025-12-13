#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n + 1);

    int mst_cost = 0;
    vector<array<int, 3>> mst_edges;

    for (auto &e : edges) {
        int w = e[0], u = e[1], v = e[2];

        if (dsu.unite(u, v)) {
            mst_cost += w;
            mst_edges.push_back({u, v, w});
        }
    }

    cout << "Minimum Spanning Tree Cost = " << mst_cost << endl;

    cout << "MST Edges:\n";
    for (auto &e : mst_edges) {
        cout << e[0] << " -- " << e[1] << "  (Weight = " << e[2] << ")\n";
    }

    return 0;
}
