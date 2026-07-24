#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void warshall(int graph[100][100],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            { 
                if(graph[i][k] != INF && graph[k][j] != INF)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int graph[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    warshall(graph,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}