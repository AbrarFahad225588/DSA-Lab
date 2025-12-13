#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl "\n" 
#define  yes cout<<"YES"<<endl;
#define  no cout<<"NO"<<endl;
ll N=1'000'000'000'000L;
map<ll,ll>r,c,l,rr;
int board[1001][1001];
int n;
bool possible(int x,int y)
{
    if(r[x]) return false;
    if(c[y]) return false;
    if(l[x+y]) return false;
    if(rr[x-y]) return false;
    return true;
}
bool nQueen(int x,int y)
{ 
    if(y==n) return false;
    if(x==n) return true;
    if(possible(x,y))
    {
        board[x][y]=1;
        r[x]=1;c[y]=1;
        l[x+y]=1;rr[x-y]=1;
        if(nQueen(x+1,0)) return true;
        board[x][y]=0;
        r[x]=0;
        c[y]=0;
        l[x+y]=0;
        rr[x-y]=0;
        return nQueen(x,y+1);
    }
    return nQueen(x,y+1);
}
void solve()
{
     cin>>n;
     memset(board,0,sizeof(board));
    //  for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<nQueen(0,0)<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{

    // int tt;
    // cin>>tt;
    // while(tt--) 

    solve();
    
    return 0;
}
