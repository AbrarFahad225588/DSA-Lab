#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<int>adj[],vector<int>&vis)
{
    vis[u]=1;
    cout<<u<<" ";
    for(int v : adj[u])
    {
       if(!vis[v])
       {
        dfs(v,adj,vis);
       }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // adj[v].push_back(u);

    }
    vector<int>vis(n,0);
    dfs(0,adj,vis);

}
