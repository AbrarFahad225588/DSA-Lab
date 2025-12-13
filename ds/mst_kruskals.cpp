#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int findParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &Rank)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b)
    {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n + 1), Rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int mstCost = 0;
    vector<Edge> mstEdges;

    for (auto e : edges)
    {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);
        if (pu != pv)
        {
            mstCost += e.w;
            mstEdges.push_back(e);
            unionSet(pu, pv, parent, Rank);
        }
    }

    cout << "MST Edges:\n";
    for (auto e : mstEdges)
    {
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    }

    cout << "Total Cost = " << mstCost << endl;

    return 0;
}
