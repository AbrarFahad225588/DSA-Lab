#include<bits/stdc++.h>
using namespace std;
void dfs_iterative(int start,vector<int>ad[],int n)
{
    vector<bool> visit(n,false);
    stack<int> st;

    st.push(start);
    visit[start]=true;
    cout<<start<<" ";
    while(!st.empty())
    {
         int i=st.top();
         st.pop();
         if(!visit[i])
         {
            cout<<i<<" ";
            visit[i]=true;
            st.push(i);
         }
               for(int x:ad[i])
               {
                  if(!visit[x])
                  {
                    st.push(x);
                  }
               }
    }
       
}
int main()
{
    int n=5;
    vector<int>adj[n];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};
    dfs_iterative(0,adj,n);
}