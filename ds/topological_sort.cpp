#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
    visited[node] = true;


    for (int neigh : adj[node]) {
        if (!visited[neigh])
            dfs(neigh, adj, visited, st);
    }

    st.push(node);
}

vector<int> topoSortDFS(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    stack<int> st;


    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}


vector<int> topoSortBFS(int n, vector<int> adj[]) {
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
        for (int neigh : adj[i])
            indegree[neigh]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }

    return topo;
}


int main() {
    int n, m;
    cin >> n >> m;   

    vector<int> adj[n];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topoDFS = topoSortDFS(n, adj);

    cout << "Topological Sort (DFS): ";
    for (int x : topoDFS) cout << x << " ";
    cout << endl;

 
    vector<int> topoBFS = topoSortBFS(n, adj);

    cout << "Topological Sort (BFS / Kahn's Algorithm): ";
    for (int x : topoBFS) cout << x << " ";
    cout << endl;

    return 0;
}
