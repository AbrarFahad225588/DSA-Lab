#include<bits/stdc++.h> 
using namespace std;
void bfs(vector<int>adj[],int n,int s,int t)
{
    vector<int>vis(n,0),parent(n,-1);
    queue<int>q;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();

        for(int v: adj[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                parent[v]=u;
                q.push(v);
            }
        }

    }
    vector<int>path;
    for(int v=t;v!=-1;v=parent[v])
    {
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    if(path[0]==s)
    {
        cout<<"Shortest path from "<<s<<" to "<<t<<": ";
        for(int v:path)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"No path from "<<s<<" to "<<t<<endl;
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
        adj[v].push_back(u);
    }
    int s,t;
    cin>>s>>t;
    bfs(adj,n,s,t);
    return 0;
}

